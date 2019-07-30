#include <mysqlx/xapi.h>
#include <iostream>
#include<string>
#include<stdlib.h>

using namespace std;

//tal shalev & or kilim

//final version



int main() {
	char err_msg[256] = {};
	int err_code = 0;
	mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "sakila", err_msg, &err_code);

	if (NULL == sess) {
		cerr << err_msg << endl;
		exit(err_code);
	}


	char* query = { "CREATE SCHEMA IF NOT EXISTS `music_world`;" };

	mysqlx_result_t* res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

	

	
	//creation of tables



	// TABLE 1

	query = { "DROP TABLE IF EXISTS 'musician'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);





	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`musician` ("\
		"`musician_id` INT NOT NULL AUTO_INCREMENT,"\
		"`name` VARCHAR(45) NOT NULL,"\
		"`phone` VARCHAR(45) NULL,"\
		"`address` VARCHAR(45) NULL,"\
		"`player` TINYINT NOT NULL,"\
		"`singer` TINYINT NOT NULL,"\
		"`collab` INT NULL,"\
		"PRIMARY KEY(`musician_id`)); " };

	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);




	query = { "LOCK TABLES 'musician' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		
		"INSERT INTO `music_world`.`musician` (`musician_id`, `name`,`phone`,`address`, `player`, `singer`,`collab`) VALUES ('10', 'bruno mars','','', '0', '1','0'),('9', 'j rocker','','', '1', '0','2'),('8', 'tupak', '','','1', '1','10'),('7', 'max h', '','','1', '1','3'),('6', '2chainz','','', '1', '1','2'),('5', 'freddie mercury','','', '1', '1','1'),('4', 'slash', '','','1', '1','4'),('3', 'eminem','','', '1', '1','15'),('2', 'bruno mars','','', '0', '1','0'),('1', 'axel rose','0504554654','', '0', '1','9');"};

	


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);






	//   TABLE 2	



	query = { "DROP TABLE IF EXISTS 'album'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`album` ("\
		"`album_id` INT NOT NULL AUTO_INCREMENT,"\
		"`name` VARCHAR(45) NOT NULL,"\
		"`number_of_songs` INT NOT NULL,"\
		"`recording_started` DATE NOT NULL,"\
		"`recording_ended` DATE NOT NULL,"\
		"`producer` VARCHAR(100) NOT NULL,"\
		"`recorder` VARCHAR(45) NOT NULL,"\
		"PRIMARY KEY(`album_id`)); " };

	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "LOCK TABLES 'album' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);




	query = {
		

	
	"insert into `music_world`.`album` (`album_id`,`name`,`number_of_songs`,`recording_started`,`recording_ended`,`producer`,`recorder`) values('10', 'fast', '3', '2005-02-10', '2015-03-11', 'drake', 'drake'), ('9', 'noise', '10', '2019-05-10', '2020-12-12', 'eminem', 'isaac jr'), ('8', 'travel time', '8', '2013-03-03', '2013-06-11', 'noize', 'dr dre'), ('7', 'rock_n_roll', '5', '1999-01-01', '2001-01-10', 'axel', 'isaac'), ('6', 'shake that', '7', '2002-01-14', '2005-06-11', 'iggy a', 'mighty z'), ('5', 'douse', '2', '2013-05-10', '2013-06-11', 'dr dre', 'isaac jr'), ('4', 'run_n_gun', '4', '2000-05-11', '2001-05-30', 'yorgen', 'micky j'), ('3', 'fire away', '10', '1996-02-11', '2000-01-01', 'eminem', 'isaac'), ('2', 'roam again', '5', '2015-05-10', '2018-06-11', 'dr dre', 'isaac jr'), ('1', 'roam', '2', '2013-05-10', '2013-06-11', 'dr dre', 'isaac jr'); "};
	





	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);




	// TABLE 3



	query = { "DROP TABLE IF EXISTS 'musical_segment'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`musical_segment` ("\
		"`segment_id` INT NOT NULL,"
		"`name` VARCHAR(45) NOT NULL,"\
		"`lyricist` VARCHAR(45) NULL,"\
		"`composer` VARCHAR(45) NOT NULL,"\
		"`length` INT NOT NULL,"\
		"`genre` VARCHAR(45) NOT NULL,"\
		"`date_of_recording` DATE NOT NULL,"\
		"`performed_by` VARCHAR(45) NOT NULL,"\
		"`in_album` INT NOT NULL,"\
		"PRIMARY KEY(`segment_id`))"\
		"; " };

	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

	query = { "LOCK TABLES 'musical_segment' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		"insert into `music_world`.`musical_segment` (`segment_id`,`name`,`lyricist`,`composer`,`length`,`genre`,`date_of_recording`,`performed_by`,`in_album`) values ('10','rise','david boom','ram jam','360','classic rock','1967-01-21','axel rose','9'),('9','railroad','2chainz','2chainz','150','dance','2014-10-11','bruno mars','7'),('8','go home','bruce silver','arazim hgg','190','pop','2018-01-01','dr dre','5'),('7','runaway','hey heyr','michas moll','200','rap','2015-06-01','eminem','3'),('6','like you','shalom tt','dona mr','274','metal','2018-01-01','eminem','1'),('5','go home','bruce silver','sher ho','277','pop','2008-06-08','axel rose','8'),('4','rise','yoav dor','dor s','171','dance','2018-01-09','bruno mars','6'),('3','hey ehy','bruce silver','michael m','270','rock','2018-01-01','axel rose','4'),('2','harmony','','mick jager','180','classic rock','1990-2-10','freddie mercury','2'),('1','welcome to the urban jungle','axel rose','axel rose','180','rock','1990-10-11','dr dre','10');" };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	// TABLE 4



	query = { "DROP TABLE IF EXISTS 'instruments'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`instruments` ("\
		"`instrument_id` INT NOT NULL,"\
		"`type` VARCHAR(45) NULL,"\
		"`manufecturer` VARCHAR(45) NULL,"\
		"`numofseg` INT NOT NULL,"
		"PRIMARY KEY(`instrument_id`)); " };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "LOCK TABLES 'instruments' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		"INSERT INTO `music_world`.`instruments` (`instrument_id`, `type`, `manufecturer`,`numofseg`) VALUES ('10', 'guitar', 'fender','22'),('9', 'microphone', 'yamaha','11'),('8', 'microphone', 'sennheiser','20'),('7', 'keyboard', 'home_keys','4'),('6', 'keyboard', 'yamaha','5'),('5', 'drums', 'metzila','1'),('4', 'drums', 'yamaha','9'),('3', 'guitar', 'washburn','10'),('2', 'guitar', 'gibson','21'),('1', 'guitar', 'yamaha','8');" };

	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	// TABLE 5


	query = { "DROP TABLE 'musiciansxalbums'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`musiciansxalbums` ("\
		"`musician_id` INT NOT NULL,"\
		"`album_id` INT NOT NULL); " };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "LOCK TABLES 'musiciansxalbums' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		"insert into `music_world`.`musiciansxalbums` (`musician_id`,`album_id`) VALUES ('10','1'),('9','2'),('8','4'),('7','1'),('6','3'),('5','7'),('4','8'),('3','4'),('2','2'),('1','3');" };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	// TABLE 6


	/*query = { "DROP TABLE IF EXISTS 'albumsxsegments'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`albumsxsegments` ("\
		"`album_id` INT NOT NULL,"\
		"`segment_id` INT NOT NULL); " };

	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


	query = { "LOCK TABLES 'albumsxsegments' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);




	query = {
		"insert into `music_world`.`albumsxsegments` (`album_id`,`segment_id`) values ('7','5'),('9','1'),('3','10'),('5','9'),('2','4'),('3','7'),('2','2'),('1','3'),('1','8');" };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);




	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

*/



	//TABLE 7

	query = { "DROP TABLE IF EXISTS 'musicianxinstruments'" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "CREATE TABLE IF NOT EXISTS `music_world`.`musicianxinstruments` ("\
		"`musician_id` INT NOT NULL,"\
		"`instrument_id` INT NOT NULL); " };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = { "LOCK TABLES 'musicianxinstruments' WRITE" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		"insert into `music_world`.`musicianxinstruments` (`musician_id`,`instrument_id`) values ('8','2'),('9','7'),('4','2'),('5','1'),('3','9'),('1','3'),('4','5'),('4','3'),('2','1'),('1','3');" };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);




	query = { "UNLOCK TABLES" };
	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

     






//defining forgien keys

	query = {
		"ALTER TABLE `music_world`.`musiciansxalbums`"\
		"CHANGE COLUMN `album_id` `album_id` INT NOT NULL ,"\
		"ADD INDEX `musicianid_idx` (`musician_id` ASC) VISIBLE,"\
		"ADD INDEX `album_idx` (`album_id` ASC) VISIBLE; "\
		";"\
		"ALTER TABLE `music_world`.`musiciansxalbums`"\
		"ADD CONSTRAINT `musicianid`"\
		"FOREIGN KEY(`musician_id`)"\
		"REFERENCES `music_world`.`musician` (`musician_id`)"\
		"ON DELETE NO ACTION"\
		"ON UPDATE NO ACTION,"\
		"ADD CONSTRAINT `album`"\
		"FOREIGN KEY(`album_id`)"\
		"REFERENCES `music_world`.`album` (`album_id`)"\
		"ON DELETE NO ACTION"\
		"ON UPDATE NO ACTION; " };

	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		"ALTER TABLE `music_world`.`musiciansxalbums`" \
		"ADD CONSTRAINT `musician_id`"\
		"FOREIGN KEY(`musician_id`)"\
		"	REFERENCES `music_world`.`musician` (`musician_id`)"\
		"ON DELETE NO ACTION"\
		"	ON UPDATE NO ACTION,"\
		"	ADD CONSTRAINT `album_id`"\
		"	FOREIGN KEY(`album_id`)"\
		"	REFERENCES `music_world`.`album` (`album_id`)"\
		"	ON DELETE NO ACTION"\
		"	ON UPDATE NO ACTION; " };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	//query = {
	//	"ALTER TABLE `music_world`.`albumsxsegments` "\
	//	"ADD INDEX `aid_idx` (`album_id` ASC) VISIBLE,"\
	//	"ADD INDEX `MSid_idx` (`segment_id` ASC) VISIBLE;"\
	//	";"\
	//	"ALTER TABLE `music_world`.`albumsxsegments`"\
	//	"	ADD CONSTRAINT `aid`"\
	//	"	FOREIGN KEY(`album_id`)"\
	//	"		REFERENCES `music_world`.`album` (`album_id`)"\
	//	"			ON DELETE NO ACTION"\
	//	"			ON UPDATE NO ACTION,"\
	//	"			ADD CONSTRAINT `MSid`"\
	//	"			FOREIGN KEY(`segment_id`)"\
	//	"				REFERENCES `music_world`.`musical_segments` (`MS_id`)"\
	//	"					ON DELETE NO ACTION"\
	//	"					ON UPDATE NO ACTION; " };


	//mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);



	query = {
		"ALTER TABLE `music_world`.`musiciansxinstruments` "\
		"ADD INDEX `mid_idx` (`musician_id` ASC) VISIBLE,"\
		"ADD INDEX `instrument_id_idx` (`instrument_id` ASC) VISIBLE;"\
		";"\
		"ALTER TABLE `music_world`.`musiciansxinstruments`"\
		"	ADD CONSTRAINT `mid`"\
		"	FOREIGN KEY(`musician_id`)"\
		"		REFERENCES `music_world`.`musician` (`musician_id`)"\
		"			ON DELETE NO ACTION"\
		"			ON UPDATE NO ACTION,"\
		"			ADD CONSTRAINT `instrument_id`"\
		"			FOREIGN KEY(`instrument_id`)"\
		"				REFERENCES `music_world`.`instruments` (`instrument_id`)"\
		"					ON DELETE NO ACTION"\
		"					ON UPDATE NO ACTION; " };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);


















	/*query = { "ALTER TABLE `music_world`.`musical_segment`"\
	"ADD COLUMN `employee_id` INT NULL AFTER `recording_date`,"\
	"ADD INDEX `employee_idx` (`employee_id` ASC) VISIBLE;"\
	";"\
	"ALTER TABLE `music_world`.`musical_segment`"\
	"ADD CONSTRAINT `employee`"\
	"FOREIGN KEY(`employee_id`)"\
	"REFERENCES `music_world`.`employees` (`employee_id`)"\
	"ON DELETE NO ACTION"\
	"ON UPDATE NO ACTION; " };


	mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);*/





	// for the user




	int choice = 0;
	while (choice != 99) {
		std::cout << "\n****************************************************************************\n*"
			<< " Welcome to your music studio. Please choose one of the following:\t   \t\t\t\t\t\t\t\t\t   \n"
			<< "* 1) amount of albums recorded between date X and Y.\t\t\t\t\t\t \n* 2) Show different songs recorded by musician X between dates y and z.\t\t\t\t\t\t\t \n"
			<< "* 3) amount of albums recorded by musician x between two dates.\t\t\t\t\t\t\t   \n* 4) The most common instrument.\t\t\t\t\t\t   \n"
			<< "* 5) number of instruments used in selected album.\t\t\t\t\t   \n* 6) most productive producer between X and Y.\t\t\t\t\t\n* 7) the commonest manufecturer.\t\t\t\t\t   \n"
			<< "* 8) all the musicians who recorded throughout the years.\t\t\t\t\t   \n* 9) the musician with the most collaborations.\t\t   \n* 10) most popular song genre.\t   \n"
			<< "* 11) most prolific recording technitian between two dates.\t   \n* 12) Show The name of the first album .   \n* 13)all the songs that are in 2 or more albums.\t\t\t\t   \n"
			<< "* 14) recorders who recorded an entire album.\t   \n* 15) the musician with the most genres performed \n* 99) End the program.\t\t\t\t\t\t\t   \n"
			<< "****************************************************************************\nYour Choice:> ";
		cin >> choice;

		mysqlx_stmt_t* stmt;

		switch (choice) {

		case 99: {
			continue;
		}

		case 1: {
			





			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);

			string x;
			string y;
			std::cout << "date format: 2010-01-01\ngive first date: ";
			getline(cin, x);
			getline(cin, x);
			std::cout << "date format: 2019-01-01\n give second date: ";
			
			getline(cin, y);

		
		
		

		string query2 = { "SELECT name FROM album WHERE DATE(recording_started)>'"+x+"' AND DATE(recording_ended)<'"+y+"'; " };
		char query[1000];

		strcpy_s(query, query2.c_str());
		


		 mysqlx_result_t*  res= mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);
		
		 //print just one

		 if (NULL != res) {
			 char buff[256]; size_t size = 0;
			 int i =1;
			 do {
				 mysqlx_row_t* row = mysqlx_row_fetch_one(res);
				 while (NULL != row) {
					 size = sizeof(buff);
					 mysqlx_get_bytes(row, 0, 0, buff, &size);
					 std::cout << buff << endl;
					 row = mysqlx_row_fetch_one(res);
					++i;
					 
				 }
				 std::cout << "\n" << "the num of albums :" << i-1<<"\n";
			 } while (RESULT_OK == mysqlx_next_result(res));
		 }
		 else {
			 cerr << mysqlx_error_message(sess) << endl;
			 exit(mysqlx_error_num(sess));
		 }

			

			break;
		}

		case 2: {
		

			string name;
			std::cout << "example name: dr dre \n input the musician you want to check: ";
			getline(cin, name);
			getline(cin, name);
			string x;
			string y;
			std::cout << "date format: 2010-01-01\ngive first date: ";
			getline(cin, x);
			//getline(cin, x);
			std::cout << "date format: 2019-01-01\n give second date: ";
			//getline(cin, y);
			getline(cin, y);
			cout << "\n";






				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



		string	query2 = { " 	SELECT NAME	from musical_segment	where	performed_by = '"+name+"'	AND	  DATE(date_of_recording)>'"+x+"' AND DATE(date_of_recording)<'"+y+"'" };

			char query[1000];

			strcpy_s(query, query2.c_str());



			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one
			int i = 0;
			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << "songs recorded by "+name+" between "+x+" and "+y+" :  " << buff << endl;
						row = mysqlx_row_fetch_one(res);
						i++;

					}
					std::cout << "\n the count of the songs: " << i;
				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}


			cout << "\n";








			break;
		}

		case 3: {
			








				string name;
			std::cout << "example name: axel rose \n input the musician you want to check: ";
			getline(cin, name);
			getline(cin, name);
			string x;
			string y;
			std::cout << "date format: 1900-01-01\ngive first date: ";
			getline(cin, x);
			//getline(cin, x);
			std::cout << "date format: 2020-12-31\n give second date: ";
			//getline(cin, y);
			getline(cin, y);
			cout << "\n";






			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			string	query2 = { " SELECT distinct album.name from musical_segment, album	where in_album = album_id and performed_by = '"+name+"'	AND	DATE(date_of_recording)>'"+x+"'	AND DATE(date_of_recording)<'"+y+"'	" };

			char query[1000];

			strcpy_s(query, query2.c_str());



			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one
			int i = 0;
			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout  << buff << endl;
						row = mysqlx_row_fetch_one(res);
						i++;

					}
					std::cout << "\n  the amount of albums recorded by " + name + " between " + x + " and " + y + " :   " << i;
				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}


			cout << "\n";










			break;
		}

		case 4: {
			
			







				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { " 	select instruments.type	from instruments group by numofseg	order by numofseg desc limit 1	  " };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << "  The most common instrument :  " << buff << endl;
						row = mysqlx_row_fetch_one(res);


					}

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}










			break;
		}

		case 5: {
			

			



				string name;
			std::cout << "example album: run_n_gun \n input the album you want to check: ";
			getline(cin, name);
			getline(cin, name);
			cout << "\n";






			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			string	query2 = { " 	select distinct instruments.type from album join musiciansxalbums using (album_id)join musician using (musician_id)join musicianxinstruments using (musician_id)join instruments using (instrument_id)where album.name = '"+name+"';" };

			char query[1000];

			strcpy_s(query, query2.c_str());



			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one
			int i = 0;
			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout  << buff << endl;
						row = mysqlx_row_fetch_one(res);
						i++;

					}
					std::cout << "\n the count of the instruments used: " << i;
				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}


			cout << "\n";





















			break;
		}

		case 6: {
			

			string x;
			string y;
			std::cout << "date format: 1998-01-01\ngive first date: ";
			getline(cin, x);
			getline(cin, x);
			std::cout << "date format:2020-12-31\n give second date: ";

			getline(cin, y);


			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



		string	query2 = {
			
			"SELECT producer, COUNT(producer) AS magnitude FROM album where DATE(recording_started)>'"+x+"' AND DATE(recording_started)<'"+y+"' GROUP BY producer ORDER BY magnitude DESC			LIMIT 1; "
			
			};

			char query[1000];

			strcpy_s(query, query2.c_str());



			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << "\n most productive producer between "+x+" and "+y+": " << buff << endl;
						row = mysqlx_row_fetch_one(res);


					}

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}

			cout << "\n";





			break;
		}

		case 7: {
		
	


				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { " 			select manufecturer, sum(numofseg) as nos from instruments	where manufecturer = 'yamaha' or manufecturer = 'metzila' or manufecturer = 'home_keys' or manufecturer = 'gibson' or manufecturer = 'fender' or manufecturer = 'sennheiser' or manufecturer = 'washburn'	group by manufecturer	order by nos desc	limit 1	" };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << "the commonest manufecturer:  " << buff << endl;
						row = mysqlx_row_fetch_one(res);


					}

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}











			break;
		}

		case 8: {
			
			






				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { "select distinct name	from musician " };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;
				int i = 0;
				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << buff << endl;
						row = mysqlx_row_fetch_one(res);
						++i;

					}
					std::cout << "\n"<< "the count of musicians: "<<i;

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}




			break;
		}

		case 9: {


		






				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { "	select name		from musician	group by collab	order by collab desc	limit 1	" };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << "the musician with the most collaborations:  " << buff << endl;
						row = mysqlx_row_fetch_one(res);


					}

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}








			
			break;
		}

		case 10: {
			
			




			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { " SELECT genre, COUNT(genre) AS magnitude FROM musical_segment GROUP BY genre	ORDER BY magnitude DESC LIMIT 1; " };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << " the most popular song genre:  " << buff << endl;
						row = mysqlx_row_fetch_one(res);


					}

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}







			break;
		}

		case 11: {


			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);

			string x;
			string y;
			std::cout << "date format: 1990-01-01\ngive first date: ";
			getline(cin, x);
			getline(cin, x);
			std::cout << "date format: 2010-01-01\n give second date: ";

			getline(cin, y);





			string query2 = { "		SELECT recorder, SUM(number_of_songs) AS total	FROM album	WHERE DATE(recording_started)>'"+x+"' AND DATE(recording_ended)<'"+y+"'	GROUP BY recorder ORDER BY total desc 	limit 1; " };
			char query[1000];

			strcpy_s(query, query2.c_str());

			cout << "\n";

			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;
				
				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout <<"most prolific recording technitian: "<< buff << endl;
						row = mysqlx_row_fetch_one(res);
				

					}
					
				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}






			
			break;
		}
		case 12: {
			
		//	Select name, min(recording_ended)from album


			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);

		

			query = { "Select name, min(recording_ended)from album; " };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;
				
				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout<<"the first album: " << buff << endl;
						row = mysqlx_row_fetch_one(res);
						

					}
					
				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}



			break;
		}

		case 13: {
			


	




				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { "select name, count(name) as counter	from musical_segment group by musical_segment.name	having counter >= 2	order by counter desc limit 10	" };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one
			int i = 0;
			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << buff << endl;
						row = mysqlx_row_fetch_one(res);
						++i;

					}


					std::cout << " the amount songs that are in 2 or more albums:  " << i;

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}












			break;
		}

		case 14: {
		



				mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { "select distinct recorder from album " };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;
				int i = 0;
				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);

					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << buff << endl;
						row = mysqlx_row_fetch_one(res);
						++i;

					}
					std::cout << "\n" << "the count of recorder: " << i;

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}



			std::cout << "\n";



			break;
		}

		case 15: {
		




			mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "2432sql", "music_world", err_msg, &err_code);



			query = { " 		SELECT performed_by,	SUM(genre = 'rock' or genre = 'classic rock' or genre = 'pop' or genre = 'metal') AS total	FROM musical_segment	GROUP BY performed_by		ORDER BY total desc	limit 1;  " };





			mysqlx_result_t*  res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);

			//print just one

			if (NULL != res) {
				char buff[256]; size_t size = 0;

				do {
					mysqlx_row_t* row = mysqlx_row_fetch_one(res);
					while (NULL != row) {
						size = sizeof(buff);
						mysqlx_get_bytes(row, 0, 0, buff, &size);
						std::cout << "the musician with the most genres played:  " << buff << endl;
						row = mysqlx_row_fetch_one(res);


					}

				} while (RESULT_OK == mysqlx_next_result(res));
			}
			else {
				cerr << mysqlx_error_message(sess) << endl;
				exit(mysqlx_error_num(sess));
			}






			break;
		}


		default: {
			std::cout << "invalid choice, Returning to the Main Menu" << endl;
			choice = 42;
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}




		}

		std::cout << "\nPress 1 to Return To the Main Menu.\nYour Choice:> " << endl;
		choice = 0;
		while (choice != 1) {
			cin >> choice;
			cin.clear();
			cin.ignore(10000, '\n');
		}


	}


	std::cout << "Have a nice day!!\nGoodbye!" << endl;

	return 0;






}




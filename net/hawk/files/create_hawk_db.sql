# Feed this file to mysql, e.g.,
# mysql -v < create_hawk_db.sql

create database hawk;
use hawk;
create table ip (
   ip char(16) NOT NULL default '0',
   hostname char(255) default NULL,
   lastping int(10) default NULL,
   primary key  (ip),
   unique key ip (ip),
   key ip_2 (ip)
) type=MyISAM comment='Table for last ping time of hosts';

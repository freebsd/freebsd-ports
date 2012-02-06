# Feed this file to mysql, e.g.,
# mysql -u root -p -v < create_hawk_db.sql

create database hawk;
use hawk;
CREATE TABLE `ip` (
  `ip` char(46) NOT NULL DEFAULT '0',
  `hostname` char(255) DEFAULT NULL,
  `lastping` int(10) DEFAULT NULL,
  `for_rev_match` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`ip`),
  UNIQUE KEY `ip` (`ip`),
  KEY `ip_2` (`ip`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Table for last ping time of hosts';

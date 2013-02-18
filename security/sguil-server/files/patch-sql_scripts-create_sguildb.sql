--- sql_scripts/create_sguildb.sql.orig	2012-10-12 21:39:20.000000000 +0000
+++ sql_scripts/create_sguildb.sql	2012-10-12 21:53:42.000000000 +0000
@@ -3,7 +3,7 @@
 -- CREATE DATABASE IF NOT EXISTS sguildb;
 -- USE sguildb;
 
--- Depreciated for MRG_MyISAM tables
+-- Deprecated for MRG_MyISAM tables
 -- CREATE TABLE event
 -- (
 --   sid			INT UNSIGNED	NOT NULL,
@@ -52,7 +52,7 @@
 --  INDEX status (status),
 --  INDEX abuse_queue (abuse_queue),
 --  INDEX abuse_sent (abuse_sent)
--- );
+-- )ENGINE=MyISAM;
 
 -- CREATE TABLE tcphdr
 -- (
@@ -66,7 +66,8 @@
 --  tcp_win	SMALLINT UNSIGNED,
 --  tcp_csum	SMALLINT UNSIGNED,
 --  tcp_urp	SMALLINT UNSIGNED,
---  PRIMARY KEY (sid,cid));
+--  PRIMARY KEY (sid,cid)
+-- )ENGINE=MyISAM;
 --
 -- CREATE TABLE udphdr
 -- (
@@ -74,7 +75,8 @@
 --  cid		INT UNSIGNED	NOT NULL,
 --  udp_len	SMALLINT UNSIGNED,
 --  udp_csum	SMALLINT UNSIGNED,
---  PRIMARY KEY (sid,cid));
+--  PRIMARY KEY (sid,cid)
+-- )ENGINE=MyISAM;
 --
 -- CREATE TABLE icmphdr
 -- (
@@ -83,14 +85,16 @@
 --  icmp_csum	SMALLINT UNSIGNED,
 --  icmp_id	SMALLINT UNSIGNED,
 --  icmp_seq	SMALLINT UNSIGNED,
---  PRIMARY KEY (sid,cid));
+--  PRIMARY KEY (sid,cid)
+-- )ENGINE=MyISAM;
 --
 -- CREATE TABLE data
 -- (
 --  sid           INT UNSIGNED    NOT NULL,
 --  cid           INT UNSIGNED    NOT NULL,
 --  data_payload	TEXT,
---  PRIMARY KEY (sid,cid));
+--  PRIMARY KEY (sid,cid)
+-- )ENGINE=MyISAM;
 
 CREATE TABLE sensor
 (
@@ -101,13 +105,13 @@
   interface	VARCHAR(255),
   description	TEXT,
   bpf_filter	TEXT,
-  updated	TIMESTAMP(14) NOT NULL,
+  updated	TIMESTAMP NOT NULL,
   active	ENUM('Y','N') DEFAULT 'Y',
   ip		VARCHAR(15) DEFAULT NULL,
   public_key	VARCHAR(255) DEFAULT NULL,
   PRIMARY KEY (sid),
   INDEX hostname_idx (hostname)
-);
+)ENGINE=MyISAM;
 
 CREATE TABLE portscan
 (
@@ -119,9 +123,10 @@
   dst_port	INT UNSIGNED,
   data		TEXT,
   INDEX ps_src_ip (src_ip),
-  INDEX ps_timestamp (timestamp));
+  INDEX ps_timestamp (timestamp)
+)ENGINE=MyISAM;
 
--- Depreciated
+-- Deprecated
 -- CREATE TABLE sessions ( 
 --  sid		INT UNSIGNED NOT NULL, 
 --  xid		BIGINT UNSIGNED NOT NULL, 
@@ -142,7 +147,8 @@
 --  INDEX server (src_ip), 
 --  INDEX client (dst_ip), 
 --  INDEX sport (src_port), 
---  INDEX cport (dst_port)); 
+--  INDEX cport (dst_port)
+-- )ENGINE=MyISAM; 
 
 CREATE TABLE status
 (
@@ -150,7 +156,7 @@
   description	VARCHAR(255) NOT NULL,
   long_desc     VARCHAR(255),
   PRIMARY KEY (status_id)
-);
+)ENGINE=MyISAM;
 
 CREATE TABLE history
 (
@@ -161,7 +167,7 @@
   status	SMALLINT UNSIGNED	NOT NULL,
   comment	VARCHAR(255),
   INDEX log_time (timestamp)
-);
+)ENGINE=MyISAM;
 
 CREATE TABLE user_info
 (
@@ -170,7 +176,7 @@
   last_login	DATETIME,
   password	VARCHAR(42),
   PRIMARY KEY (uid)
-);
+)ENGINE=MyISAM;
 
 CREATE TABLE nessus_data
 (
@@ -179,7 +185,8 @@
   nessus_id     INT UNSIGNED,
   level	        VARCHAR(20),
   description		TEXT,
-  INDEX rid (rid));
+  INDEX rid (rid)
+)ENGINE=MyISAM;
 
 CREATE TABLE nessus
 (
@@ -189,7 +196,8 @@
   timestart     DATETIME,
   timeend       DATETIME,
   PRIMARY KEY (rid),
-  INDEX ip (ip));
+  INDEX ip (ip)
+)ENGINE=MyISAM;
 
 CREATE TABLE IF NOT EXISTS `pads`
 (
@@ -204,10 +212,10 @@
   application           VARCHAR(255)     NOT NULL,
   hex_payload           VARCHAR(255),
   PRIMARY KEY (sid,asset_id)
-);
+)ENGINE=MyISAM;
 
 --
--- Depreciated for MERGE tables
+-- Deprecated for MERGE tables
 -- CREATE TABLE sancp
 -- (
 --  sid		INT UNSIGNED	NOT NULL,
@@ -232,7 +240,7 @@
 --  INDEX dst_port (dst_port),
 --  INDEX src_port (src_port),
 --  INDEX start_time (start_time)
--- );
+-- )ENGINE=MyISAM;
 --
 
 INSERT INTO status (status_id, description, long_desc) VALUES (0, "New", "Real Time Event");
@@ -251,7 +259,7 @@
 (
   version	VARCHAR(32),
   installed	DATETIME
-);
+)ENGINE=MyISAM;
 
 INSERT INTO version (version, installed) VALUES ("0.13", now());
 

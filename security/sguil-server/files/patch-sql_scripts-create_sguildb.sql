--- sql_scripts/create_sguildb.sql.orig	2007-03-17 02:43:37.000000000 +0000
+++ sql_scripts/create_sguildb.sql	2011-08-09 22:21:09.000000000 +0000
@@ -52,10 +52,10 @@
 --  INDEX status (status),
 --  INDEX abuse_queue (abuse_queue),
 --  INDEX abuse_sent (abuse_sent)
---);
+-- );

---CREATE TABLE tcphdr
---(
+-- CREATE TABLE tcphdr
+-- (
 --  sid		INT UNSIGNED	NOT NULL,
 --  cid		INT UNSIGNED	NOT NULL,
 --  tcp_seq	INT UNSIGNED,
@@ -68,16 +68,16 @@
 --  tcp_urp	SMALLINT UNSIGNED,
 --  PRIMARY KEY (sid,cid));
 --
---CREATE TABLE udphdr
---(
+-- CREATE TABLE udphdr
+-- (
 --  sid		INT UNSIGNED	NOT NULL,
 --  cid		INT UNSIGNED	NOT NULL,
 --  udp_len	SMALLINT UNSIGNED,
 --  udp_csum	SMALLINT UNSIGNED,
 --  PRIMARY KEY (sid,cid));
 --
---CREATE TABLE icmphdr
---(
+-- CREATE TABLE icmphdr
+-- (
 --  sid		INT UNSIGNED	NOT NULL,
 --  cid		INT UNSIGNED	NOT NULL,
 --  icmp_csum	SMALLINT UNSIGNED,
@@ -85,8 +85,8 @@
 --  icmp_seq	SMALLINT UNSIGNED,
 --  PRIMARY KEY (sid,cid));
 --
---CREATE TABLE data
---(
+-- CREATE TABLE data
+-- (
 --  sid           INT UNSIGNED    NOT NULL,
 --  cid           INT UNSIGNED    NOT NULL,
 --  data_payload	TEXT,
@@ -101,13 +101,13 @@
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
+) ENGINE=MyISAM;

 CREATE TABLE portscan
 (
@@ -119,7 +119,8 @@
   dst_port	INT UNSIGNED,
   data		TEXT,
   INDEX ps_src_ip (src_ip),
-  INDEX ps_timestamp (timestamp));
+  INDEX ps_timestamp (timestamp)
+) ENGINE=MyISAM;

 -- Depreciated
 -- CREATE TABLE sessions (
@@ -150,7 +151,7 @@
   description	VARCHAR(255) NOT NULL,
   long_desc     VARCHAR(255),
   PRIMARY KEY (status_id)
-);
+) ENGINE=MyISAM;

 CREATE TABLE history
 (
@@ -161,7 +162,7 @@
   status	SMALLINT UNSIGNED	NOT NULL,
   comment	VARCHAR(255),
   INDEX log_time (timestamp)
-);
+) ENGINE=MyISAM;

 CREATE TABLE user_info
 (
@@ -169,7 +170,7 @@
   username	VARCHAR(16)	NOT NULL,
   last_login	DATETIME	NOT NULL,
   PRIMARY KEY (uid)
-);
+) ENGINE=MyISAM;

 CREATE TABLE nessus_data
 (
@@ -178,7 +179,8 @@
   nessus_id     INT UNSIGNED,
   level	        VARCHAR(20),
   description		TEXT,
-  INDEX rid (rid));
+  INDEX rid (rid)
+) ENGINE=MyISAM;

 CREATE TABLE nessus
 (
@@ -188,7 +190,8 @@
   timestart     DATETIME,
   timeend       DATETIME,
   PRIMARY KEY (rid),
-  INDEX ip (ip));
+  INDEX ip (ip)
+) ENGINE=MyISAM;

 CREATE TABLE IF NOT EXISTS `pads`
 (
@@ -203,12 +206,12 @@
   application           VARCHAR(255)     NOT NULL,
   hex_payload           VARCHAR(255),
   PRIMARY KEY (sid,asset_id)
-);
+) ENGINE=MyISAM;

 --
 -- Depreciated for MERGE tables
---CREATE TABLE sancp
---(
+-- CREATE TABLE sancp
+-- (
 --  sid		INT UNSIGNED	NOT NULL,
 --  sancpid	BIGINT UNSIGNED	NOT NULL,
 --  start_time	DATETIME	NOT NULL,
@@ -231,8 +234,8 @@
 --  INDEX dst_port (dst_port),
 --  INDEX src_port (src_port),
 --  INDEX start_time (start_time)
---);
---
+-- );
+--

 INSERT INTO status (status_id, description, long_desc) VALUES (0, "New", "Real Time Event");
 INSERT INTO status (status_id, description, long_desc) VALUES (1, "No Further Action Required", "No Further Action Required");
@@ -250,7 +253,7 @@
 (
   version	VARCHAR(32),
   installed	DATETIME
-);
+) ENGINE=MyISAM;

 INSERT INTO version (version, installed) VALUES ("0.12", now());


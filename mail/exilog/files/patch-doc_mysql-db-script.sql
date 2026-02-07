--- doc/mysql-db-script.sql.orig	2005-07-22 08:57:03 UTC
+++ doc/mysql-db-script.sql
@@ -15,12 +15,12 @@
 
 CREATE TABLE `deferrals` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary NOT NULL default '',
+  `message_id` varchar(23) binary NOT NULL default '',
   `timestamp` bigint(20) NOT NULL default '0',
   `rcpt` varchar(200) NOT NULL default '',
   `rcpt_intermediate` varchar(200) default NULL,
   `rcpt_final` varchar(200) NOT NULL default '',
-  `host_addr` varchar(15) default NULL,
+  `host_addr` varchar(45) default NULL,
   `host_dns` varchar(255) default NULL,
   `tls_cipher` varchar(128) default NULL,
   `router` varchar(128) default NULL,
@@ -43,12 +43,12 @@ CREATE TABLE `deferrals` (
 
 CREATE TABLE `deliveries` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary NOT NULL default '',
+  `message_id` varchar(23) binary NOT NULL default '',
   `timestamp` bigint(20) NOT NULL default '0',
   `rcpt` varchar(200) NOT NULL default '',
   `rcpt_intermediate` varchar(200) default NULL,
   `rcpt_final` varchar(200) NOT NULL default '',
-  `host_addr` varchar(15) default NULL,
+  `host_addr` varchar(45) default NULL,
   `host_dns` varchar(255) default NULL,
   `tls_cipher` varchar(128) default NULL,
   `router` varchar(128) default NULL,
@@ -71,12 +71,12 @@ CREATE TABLE `deliveries` (
 
 CREATE TABLE `errors` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary NOT NULL default '',
+  `message_id` varchar(23) binary NOT NULL default '',
   `timestamp` bigint(20) NOT NULL default '0',
   `rcpt` varchar(200) NOT NULL default '',
   `rcpt_intermediate` varchar(200) default NULL,
   `rcpt_final` varchar(200) NOT NULL default '',
-  `host_addr` varchar(15) default NULL,
+  `host_addr` varchar(45) default NULL,
   `host_dns` varchar(255) default NULL,
   `tls_cipher` varchar(128) default NULL,
   `router` varchar(128) default NULL,
@@ -99,12 +99,12 @@ CREATE TABLE `errors` (
 
 CREATE TABLE `messages` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary NOT NULL default '',
+  `message_id` varchar(23) binary NOT NULL default '',
   `timestamp` bigint(20) default NULL,
   `msgid` varchar(255) default NULL,
   `completed` bigint(20) default NULL,
   `mailfrom` varchar(255) default NULL,
-  `host_addr` varchar(15) default NULL,
+  `host_addr` varchar(45) default NULL,
   `host_rdns` varchar(255) default NULL,
   `host_ident` varchar(255) default NULL,
   `host_helo` varchar(255) default NULL,
@@ -132,7 +132,7 @@ CREATE TABLE `messages` (
 
 CREATE TABLE `queue` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary NOT NULL default '',
+  `message_id` varchar(23) binary NOT NULL default '',
   `mailfrom` varchar(255) NOT NULL default '',
   `timestamp` bigint(20) NOT NULL default '0',
   `num_dsn` int(11) NOT NULL default '0',
@@ -162,9 +162,9 @@ CREATE TABLE `queue` (
 
 CREATE TABLE `rejects` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary default NULL,
+  `message_id` varchar(23) binary default NULL,
   `timestamp` bigint(20) NOT NULL default '0',
-  `host_addr` varchar(15) NOT NULL default '',
+  `host_addr` varchar(45) NOT NULL default '',
   `host_rdns` varchar(255) NOT NULL default '',
   `host_ident` varchar(255) default NULL,
   `host_helo` varchar(255) default NULL,
@@ -188,7 +188,7 @@ CREATE TABLE `rejects` (
 
 CREATE TABLE `unknown` (
   `server` varchar(32) NOT NULL default '',
-  `message_id` varchar(16) binary NOT NULL default '',
+  `message_id` varchar(23) binary NOT NULL default '',
   `timestamp` bigint(20) NOT NULL default '0',
   `line` varchar(255) NOT NULL default '',
   PRIMARY KEY  (`server`,`message_id`,`timestamp`,`line`),

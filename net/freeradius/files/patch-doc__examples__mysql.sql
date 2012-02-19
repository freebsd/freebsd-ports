--- ./doc/examples/mysql.sql.orig	2012-02-19 08:51:58.000000000 -0500
+++ ./doc/examples/mysql.sql	2012-02-19 08:54:03.000000000 -0500
@@ -125,7 +125,7 @@
   user varchar(64) NOT NULL default '',
   pass varchar(64) NOT NULL default '',
   reply varchar(32) NOT NULL default '',
-  date timestamp(14) NOT NULL,
+  date timestamp NOT NULL,
   PRIMARY KEY  (id)
 ) ;
 

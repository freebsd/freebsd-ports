--- lib/defines.php.orig        Tue Mar  8 04:07:23 2005
+++ lib/defines.php     Thu Jul 20 21:51:35 2006
@@ -1,7 +1,7 @@
 <?php
 
 define ("WEBROOT", "http://domainname.com/asterisk-stat/");
-define ("FSROOT", "/var/www/html/HTTP2/Asterisk/asterisk-stat-v2/");
+define ("FSROOT", "/usr/local/www/asterisk-stat/");
 
 
 
@@ -9,11 +9,11 @@
 
 
 define ("HOST", "localhost");
-define ("PORT", "5432");
-define ("USER", "postgres");
+define ("PORT", "3306");
+define ("USER", "asterisk");
 define ("PASS", "");
-define ("DBNAME", "cdrasterisk");
-define ("DB_TYPE", "postgres"); // mysql or postgres
+define ("DBNAME", "asterisk");
+define ("DB_TYPE", "mysql"); // mysql or postgres
 
 
 define ("DB_TABLENAME", "cdr");

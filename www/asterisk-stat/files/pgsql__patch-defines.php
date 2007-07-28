--- lib/defines.php.orig        Tue Mar  8 04:07:23 2005
+++ lib/defines.php     Sat Jun 23 07:26:44 2007
@@ -1,7 +1,7 @@
 <?php
 
 define ("WEBROOT", "http://domainname.com/asterisk-stat/");
-define ("FSROOT", "/var/www/html/HTTP2/Asterisk/asterisk-stat-v2/");
+define ("FSROOT", "/usr/local/www/asterisk-stat/");
 
 
 
@@ -10,9 +10,9 @@
 
 define ("HOST", "localhost");
 define ("PORT", "5432");
-define ("USER", "postgres");
+define ("USER", "asterisk");
 define ("PASS", "");
-define ("DBNAME", "cdrasterisk");
+define ("DBNAME", "asterisk");
 define ("DB_TYPE", "postgres"); // mysql or postgres
 
 

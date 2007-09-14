--- inc/db.php.orig	Fri Sep 14 06:25:32 2007
+++ inc/db.php	Fri Sep 14 06:36:13 2007
@@ -50,7 +50,7 @@
       if (mysql_select_db(DB_DATABASE)) {
         $rc = TRUE;
       } else {
-        $rc = mysql_create_db(DB_DATABASE);
+        $rc = mysql_query('CREATE DATABASE ' . DB_DATABASE);
       }
       mysql_close();
       return $rc;

--- ./functions.inc.php.orig	2005-01-07 07:00:00.000000000 +0800
+++ ./functions.inc.php	2008-05-17 21:19:54.000000000 +0800
@@ -129,7 +129,12 @@
    if (get_magic_quotes_gpc () == 0)
    {
       if ($CONF['database_type'] == "mysql")  $escaped_string = mysql_real_escape_string ($string);
-      if ($CONF['database_type'] == "mysqli")  $escaped_string = mysqli_real_escape_string ($string);
+      if ($CONF['database_type'] == "mysqli")
+      {
+         $link = db_connect ();
+         $escaped_string = mysqli_real_escape_string ($link, $string);
+         mysqli_close ($link);
+      }
       if ($CONF['database_type'] == "pgsql")  $escaped_string = pg_escape_string ($string);
    }
    else

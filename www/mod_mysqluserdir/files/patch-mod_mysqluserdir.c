--- mod_mysqluserdir.c.orig	Sun Oct 28 14:08:24 2001
+++ mod_mysqluserdir.c	Sun Oct 28 14:08:53 2001
@@ -614,7 +614,6 @@
 
 	if (sql_row=mysql_fetch_row(result)) {
 		values=sql_row[0];
-		mysql_free_result(result);
 		}
 
 	else	

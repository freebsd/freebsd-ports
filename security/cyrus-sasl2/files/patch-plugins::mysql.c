Index: plugins/mysql.c
diff -u plugins/mysql.c.orig plugins/mysql.c
--- plugins/mysql.c.orig	Thu May 15 03:46:02 2003
+++ plugins/mysql.c	Tue Jul  1 02:00:55 2003
@@ -326,6 +326,7 @@
 				"mysql plugin try and connect to %s\n",
 				cur_host);
 
+	mysql_init(&mysql);
 	sock = mysql_real_connect(&mysql,cur_host,
 				  settings->mysql_user,
 			          settings->mysql_passwd,

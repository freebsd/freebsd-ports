--- plugins/mysql.c.orig	Fri Mar  7 13:26:42 2003
+++ plugins/mysql.c	Fri Mar  7 13:30:38 2003
@@ -325,8 +325,15 @@
 	    sparams->utils->log(NULL, SASL_LOG_WARN,
 				"mysql plugin try and connect to %s\n",
 				cur_host);
+#ifdef HAVE_MYSQL_REAL_CONNECT
+	mysql_init(&mysql);
+	sock = mysql_real_connect(&mysql,cur_host,settings->mysql_user,
+				  settings->mysql_passwd,
+				  NULL,0,NULL,CLIENT_COMPRESS);
+#else
 	sock = mysql_connect(&mysql,cur_host,settings->mysql_user,
 			     settings->mysql_passwd);
+#endif
 	if (sock) break;
 	
 	cur_host = db_host;


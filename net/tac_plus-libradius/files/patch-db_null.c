--- ./db_null.c.orig	2000-12-18 17:58:02.000000000 +0100
+++ ./db_null.c	2011-08-29 00:31:55.000000000 +0200
@@ -48,9 +48,7 @@
 char *a_username;
 char *elapsed_time;char *bytes_in;char *bytes_out;
 {
-report(LOG_INFO,"Db accounting user=%s pass=%s host=%s 
-db_name=%s table=%s servern=%s clientn=%s username=%s et=%s bi=%s bo=%s",db_user,db_password,db_hostname,
-db_name,db_table,s_name,c_name,a_username,elapsed_time,bytes_in,bytes_out);
+report(LOG_INFO,"Db accounting user=%s pass=%s host=%s db_name=%s table=%s servern=%s clientn=%s username=%s et=%s bi=%s bo=%s",db_user,db_password,db_hostname, db_name,db_table,s_name,c_name,a_username,elapsed_time,bytes_in,bytes_out);
 return (1);
 }
 #endif

--- functions/mysql.c.orig	Thu Jun  3 13:17:04 2004
+++ functions/mysql.c	Thu Jun  3 13:17:09 2004
@@ -785,7 +785,9 @@
 void php3_mysql_create_db(INTERNAL_FUNCTION_PARAMETERS)
 {
 	pval *db,*mysql_link;
-	int id,type;
+	int id,type,res;
+	char *qbuf;
+	size_t qsize;
 	MYSQL *mysql;
 	MySQL_TLS_VARS;
 
@@ -818,7 +820,12 @@
 	}
 	
 	convert_to_string(db);
-	if (mysql_create_db(mysql,db->value.str.val)==0) {
+	qsize = strlen(db->value.str.val) + 20;
+	qbuf = (char *)emalloc(qsize);
+	snprintf(qbuf, qsize, "CREATE DATABASE %s", db->value.str.val);
+	res = mysql_real_query(mysql,qbuf,strlen(qbuf));
+	efree(qbuf);
+	if (res) {
 		RETURN_TRUE;
 	} else {
 		RETURN_FALSE;
@@ -831,7 +838,9 @@
 void php3_mysql_drop_db(INTERNAL_FUNCTION_PARAMETERS)
 {
 	pval *db,*mysql_link;
-	int id,type;
+	int id,type,res;
+	char *qbuf;
+	size_t qsize;
 	MYSQL *mysql;
 	MySQL_TLS_VARS;
 
@@ -864,7 +873,12 @@
 	}
 	
 	convert_to_string(db);
-	if (mysql_drop_db(mysql,db->value.str.val)==0) {
+	qsize = strlen(db->value.str.val) + 20;
+	qbuf = (char *)emalloc(qsize);
+	snprintf(qbuf, qsize, "DROP DATABASE %s", db->value.str.val);
+	res = mysql_real_query(mysql,qbuf,strlen(qbuf));
+	efree(qbuf);
+	if (res) {
 		RETURN_TRUE;
 	} else {
 		RETURN_FALSE;

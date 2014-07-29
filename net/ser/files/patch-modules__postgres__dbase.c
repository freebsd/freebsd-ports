diff -ruN modules/postgres/dbase.c /home/snar/ser-0.9.7/modules/postgres/dbase.c
--- modules/postgres/dbase.c	2005-07-20 21:11:52.000000000 +0400
+++ modules/postgres/dbase.c	2006-10-25 23:32:10.000000000 +0400
@@ -49,6 +49,9 @@
 #include "con_postgres.h"
 #include "aug_std.h"
 
+#define ERR_BUF_SIZE 256 /* tmp. buf for building the error message */
+
+
 long getpid();
 
 static char sql_buf[SQL_BUF_LEN];
@@ -124,8 +127,8 @@
 	if(parse_sql_url(CON_SQLURL(_h),
 		&user,&password,&host,&port,&database) < 0)
 	{
-		char buf[256];
-		sprintf(buf, "Error while parsing %s", _db_url);
+		char buf[ERR_BUF_SIZE];
+		snprintf(buf, ERR_BUF_SIZE, "Error while parsing %s", _db_url);
 		PLOG("connect_db", buf);
 
 		aug_free(CON_SQLURL(_h));
@@ -358,8 +361,8 @@
 		/*
 		** log the error
 		*/
-		char buf[256];
-		sprintf(buf, "query '%s', result '%s'\n",
+		char buf[ERR_BUF_SIZE];
+		snprintf(buf, ERR_BUF_SIZE, "query '%s', result '%s'\n",
 			_s, PQerrorMessage(CON_CONNECTION(_h)));
 		PLOG("submit_query", buf);
 	}
@@ -487,8 +490,8 @@
 			/*
 			** our attempt to fix the connection failed
 			*/
-			char buf[256];
-			sprintf(buf, "no connection, FATAL %d!", rv);
+			char buf[ERR_BUF_SIZE];
+			snprintf(buf, ERR_BUF_SIZE, "no connection, FATAL %d!", rv);
 			PLOG("begin_transaction",buf);
 			return(rv);
 		}
@@ -507,8 +510,8 @@
 	mr = PQexec(CON_CONNECTION(_h), "BEGIN");
 	if(!mr || PQresultStatus(mr) != PGRES_COMMAND_OK)
 	{
-		char buf[256];
-		sprintf("FATAL %s, '%s'!\n",
+		char buf[ERR_BUF_SIZE];
+		snprintf(buf, ERR_BUF_SIZE, "FATAL %s, '%s'!\n",
 			PQerrorMessage(CON_CONNECTION(_h)), _s);
 		PLOG("begin_transaction", buf);
 		return(-1);

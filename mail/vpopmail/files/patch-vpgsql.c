diff -urN -x .svn ../../vendor/vpopmail/vpgsql.c ./vpgsql.c
--- ../../vendor/vpopmail/vpgsql.c	Fri Jan 26 15:59:16 2007
+++ ./vpgsql.c	Fri Jan 26 17:01:33 2007
@@ -390,13 +390,15 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
-    qnprintf( sqlBufUpdate, SQL_BUF_SIZE,
+#ifdef ENABLE_SQL_REMOVE_DELETED
+    qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
        "delete from vlog where domain = '%s'", domain );
     pgres=PQexec(pgc, SqlBufUpdate);
-    if( !pgres || PGresultStatus(pgres)!=PGRES_COMMAND_OK) {
+    if( !pgres || PQresultStatus(pgres)!=PGRES_COMMAND_OK) {
       return(-1);
     }
 #endif
+#endif
     return(0);
 }
 
@@ -443,13 +445,15 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
-    qnprintf( sqlBufUpdate, SQL_BUF_SIZE,
+#ifdef ENABLE_SQL_REMOVE_DELETED
+    qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
         "delete from vlog where domain = '%s' and user='%s'", 
        domain, user );
     pgres=PQexec(pgc, SqlBufUpdate);
-    if( !pgres || PGresultStatus(pgres)!=PGRES_COMMAND_OK) {
+    if( !pgres || PQresultStatus(pgres)!=PGRES_COMMAND_OK) {
       err = -1;
     }
+#endif
 #endif
 
   return(err);

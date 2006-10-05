diff -urN -x .svn ../../vendor/vpopmail/vmysql.c ./vmysql.c
--- ../../vendor/vpopmail/vmysql.c	Wed Oct  4 13:19:16 2006
+++ ./vmysql.c	Wed Oct  4 16:08:34 2006
@@ -579,12 +579,14 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
        "delete from vlog where domain = '%s'", domain );
     if (mysql_query(&mysql_update,SqlBufUpdate)) {
        return(-1);
     }
 #endif
+#endif
 
     vdel_limits(domain);
 
@@ -628,12 +630,14 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
         "delete from vlog where domain = '%s' and user = '%s'", 
        domain, user );
     if (mysql_query(&mysql_update,SqlBufUpdate)) {
         err = -1;
     }
+#endif
 #endif
     return(err);
 }

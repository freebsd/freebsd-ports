diff -urN -x .svn ../../vendor/vpopmail/vpgsql.c ./vpgsql.c
--- ../../vendor/vpopmail/vpgsql.c	Wed Oct  4 13:19:16 2006
+++ ./vpgsql.c	Sun Oct  8 17:20:54 2006
@@ -16,6 +16,7 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
  */
+#include <ctype.h>
 #include <pwd.h>
 #include <unistd.h>
 #include <stdio.h>
@@ -389,13 +390,15 @@
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
 
@@ -442,13 +445,15 @@
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

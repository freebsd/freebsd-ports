diff -urN -x .svn ../../vendor/vpopmail/vpgsql.c ./vpgsql.c
--- ../../vendor/vpopmail/vpgsql.c	Wed Oct  4 13:19:16 2006
+++ ./vpgsql.c	Wed Oct  4 21:26:53 2006
@@ -16,6 +16,7 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
  */
+#include <ctype.h>
 #include <pwd.h>
 #include <unistd.h>
 #include <stdio.h>
@@ -389,6 +390,7 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( sqlBufUpdate, SQL_BUF_SIZE,
        "delete from vlog where domain = '%s'", domain );
     pgres=PQexec(pgc, SqlBufUpdate);
@@ -396,6 +398,7 @@
       return(-1);
     }
 #endif
+#endif
     return(0);
 }
 
@@ -442,6 +445,7 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( sqlBufUpdate, SQL_BUF_SIZE,
         "delete from vlog where domain = '%s' and user='%s'", 
        domain, user );
@@ -449,6 +453,7 @@
     if( !pgres || PGresultStatus(pgres)!=PGRES_COMMAND_OK) {
       err = -1;
     }
+#endif
 #endif
 
   return(err);

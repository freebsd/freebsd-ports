--- sasldb/db_ndbm.c.orig	2012-01-27 23:31:36 UTC
+++ sasldb/db_ndbm.c
@@ -44,6 +44,7 @@
  */
 
 #include <config.h>
+#include <errno.h>
 #include <stdio.h>
 #include <ndbm.h>
 #include <fcntl.h>
@@ -101,7 +102,8 @@ int _sasldb_getdata(const sasl_utils_t *
   }
   db = dbm_open(path, O_RDONLY, S_IRUSR | S_IWUSR);
   if (! db) {
-      utils->seterror(cntxt, 0, "Could not open db");
+      utils->seterror(cntxt, 0, "Could not open db `%s': %s",
+		      path, strerror(errno));
       result = SASL_FAIL;
       goto cleanup;
   }
@@ -182,10 +184,11 @@ int _sasldb_putdata(const sasl_utils_t *
 		O_RDWR | O_CREAT,
 		S_IRUSR | S_IWUSR);
   if (! db) {
+      utils->seterror(conn, 0, "Could not open db `%s' for writing: %s",
+		      path, strerror(errno));
       utils->log(conn, SASL_LOG_ERR,
 		 "SASL error opening password file. "
 		 "Do you have write permissions?\n");
-      utils->seterror(conn, 0, "Could not open db for write");
       goto cleanup;
   }
   dkey.dptr = key;
@@ -322,7 +325,8 @@ sasldb_handle _sasldb_getkeyhandle(const
     db = dbm_open(path, O_RDONLY, S_IRUSR | S_IWUSR);
 
     if(!db) {
-	utils->seterror(conn, 0, "Could not open db");
+	utils->seterror(conn, 0, "Could not open db `%s': %s",
+			path, strerror(errno));
 	return NULL;
     }
 

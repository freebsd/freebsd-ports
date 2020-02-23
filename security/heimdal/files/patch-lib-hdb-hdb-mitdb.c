--- lib/hdb/hdb-mitdb.c.orig	2019-06-07 06:21:39 UTC
+++ lib/hdb/hdb-mitdb.c
@@ -1116,7 +1116,7 @@ krb5_error_code
 hdb_mitdb_create(krb5_context context, HDB **db,
 		 const char *filename)
 {
-    MITDB **mdb (MITDB **)db;
+    MITDB **mdb = (MITDB **)db;
     *mdb = calloc(1, sizeof(**mdb));
     if (*mdb == NULL) {
 	krb5_set_error_message(context, ENOMEM, "malloc: out of memory");

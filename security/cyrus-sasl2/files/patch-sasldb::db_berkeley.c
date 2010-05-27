Index: sasldb/db_berkeley.c
diff -u -p sasldb/db_berkeley.c.orig sasldb/db_berkeley.c
--- sasldb/db_berkeley.c.orig	2009-04-29 00:09:18.000000000 +0900
+++ sasldb/db_berkeley.c	2010-05-27 14:25:14.458302060 +0900
@@ -100,7 +100,7 @@ static int berkeleydb_open(const sasl_ut
     ret = db_create(mbdb, NULL, 0);
     if (ret == 0 && *mbdb != NULL)
     {
-#if DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1
+#if (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1) || DB_VERSION_MAJOR >= 5
 	ret = (*mbdb)->open(*mbdb, NULL, path, NULL, DB_HASH, flags, 0660);
 #else
 	ret = (*mbdb)->open(*mbdb, path, NULL, DB_HASH, flags, 0660);

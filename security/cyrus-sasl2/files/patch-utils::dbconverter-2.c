Index: utils/dbconverter-2.c
diff -u -p utils/dbconverter-2.c.orig utils/dbconverter-2.c
--- utils/dbconverter-2.c.orig	2003-02-14 04:56:17.000000000 +0900
+++ utils/dbconverter-2.c	2010-05-27 14:28:26.249314464 +0900
@@ -214,7 +214,7 @@ static int berkeleydb_open(const char *p
     ret = db_create(mbdb, NULL, 0);
     if (ret == 0 && *mbdb != NULL)
     {
-#if DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1
+#if (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1) || DB_VERSION_MAJOR >= 5
 	ret = (*mbdb)->open(*mbdb, NULL, path, NULL, DB_HASH, DB_CREATE, 0664);
 #else
 	ret = (*mbdb)->open(*mbdb, path, NULL, DB_HASH, DB_CREATE, 0664);

--- filedupe.c.orig	Wed Apr 11 00:27:15 2001
+++ filedupe.c	Wed Apr 11 00:27:32 2001
@@ -8,7 +8,7 @@
 
 #include "md5.h"
 
-#define DBNAME "your_database"
+#define DBNAME "/var/db/filedupe.db"
 
 int lookup(void *md5sum, int size);
 int addfile(void *md5sum, int size);

--- cdb_seek.c.orig
+++ cdb_seek.c
@@ -1,6 +1,5 @@
 #include <sys/types.h>
 #include <errno.h>
-extern int errno;
 #include "cdb.h"
 
 #ifndef SEEK_SET

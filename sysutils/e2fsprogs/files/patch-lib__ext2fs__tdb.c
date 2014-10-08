--- lib/ext2fs/tdb.c.orig	2014-06-25 19:19:40 UTC
+++ lib/ext2fs/tdb.c
@@ -36,7 +36,6 @@
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
-#define _XOPEN_SOURCE 600
 
 #include "config.h"
 #include <unistd.h>

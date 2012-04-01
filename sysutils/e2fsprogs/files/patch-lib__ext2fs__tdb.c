--- ./lib/ext2fs/tdb.c.orig	2012-03-18 19:18:33.000000000 +0100
+++ ./lib/ext2fs/tdb.c	2012-04-01 17:15:49.000000000 +0200
@@ -36,7 +36,6 @@
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
-#define _XOPEN_SOURCE 600
 
 #include "config.h"
 #include <unistd.h>

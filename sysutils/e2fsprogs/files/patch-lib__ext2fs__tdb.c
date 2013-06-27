--- ./lib/ext2fs/tdb.c.orig	2012-07-06 15:37:27.000000000 +0200
+++ ./lib/ext2fs/tdb.c	2013-06-27 00:38:52.000000000 +0200
@@ -36,7 +36,6 @@
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
-#define _XOPEN_SOURCE 600
 
 #include "config.h"
 #include <unistd.h>

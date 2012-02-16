--- ./lib/ext2fs/tdb.c.orig	2011-11-29 16:50:04.000000000 +0100
+++ ./lib/ext2fs/tdb.c	2012-02-16 00:35:12.000000000 +0100
@@ -36,7 +36,6 @@
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
-#define _XOPEN_SOURCE 600
 
 #include "config.h"
 #include <unistd.h>

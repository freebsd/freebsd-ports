--- a/lib/ext2fs/tdb.c.orig	2008-09-16 01:55:27.000000000 +0200
+++ b/lib/ext2fs/tdb.c	2008-09-16 01:55:34.000000000 +0200
@@ -36,7 +36,6 @@
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
-#define _XOPEN_SOURCE 600
 
 #include <unistd.h>
 #include <stdio.h>

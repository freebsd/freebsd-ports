--- a/lib/ext2fs/tdb.c.orig	Thu Apr  5 02:43:05 2007
+++ b/lib/ext2fs/tdb.c	Sat Jun 30 16:13:15 2007
@@ -36,7 +36,6 @@
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
-#define _XOPEN_SOURCE 500
 
 #include <unistd.h>
 #include <stdio.h>

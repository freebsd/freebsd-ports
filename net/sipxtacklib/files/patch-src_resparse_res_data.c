--- src/resparse/res_data.c.orig	Wed Sep  5 14:44:28 2007
+++ src/resparse/res_data.c	Wed Sep  5 14:46:36 2007
@@ -20,6 +20,9 @@
 #endif /* LIBC_SCCS and not lint */
 
 #include <sys/types.h>
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #include <time.h>
 
 /* Reordered includes and separated into win/vx --GAT */
@@ -51,7 +54,8 @@
 
 #include "resparse/res_config.h"
 
-#ifndef __pingtel_on_posix__
+#if !defined(__pingtel_on_posix__) || (defined(__FreeBSD__) && __FreeBSD_version > 700040)
+/* libc _res_opcodes was removed from FreeBSD 7.x */
 const char *_res_opcodes[] = {
         "QUERY",
         "IQUERY",

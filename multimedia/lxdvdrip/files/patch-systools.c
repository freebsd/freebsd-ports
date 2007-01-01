--- systools.c.orig	Fri Dec 15 14:15:09 2006
+++ systools.c	Sat Dec 16 13:06:19 2006
@@ -11,6 +11,10 @@
 ================================================================================
 
 ==============================================================================*/
+#if defined(HAVE_SYS_PARAM_H) || ((defined(__unix__) || defined(unix)) && !defined(USG))
+#include <sys/param.h>
+#endif
+
 #define __USE_LARGEFILE64
 #define _LARGEFILE64_SOURCE
 #include <stdio.h>
@@ -18,7 +22,12 @@
 #include <stdint.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#if (defined(BSD) && (BSD >= 199306))
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>

--- mt.c.orig	Mon Jan 24 19:26:58 2005
+++ mt.c	Mon Jan 24 19:30:39 2005
@@ -1,6 +1,10 @@
 #include "version.h"
 
 #define _LARGEFILE64_SOURCE	/* required for GLIBC to enable stat64 and friends */
+#if defined(__FreeBSD__)
+#define off64_t off_t
+#define stat64 stat
+#endif
 #include <ctype.h>
 #include <sys/types.h>
 #include <pwd.h>

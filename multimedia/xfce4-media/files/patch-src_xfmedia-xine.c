--- src/xfmedia-xine.c.orig	Thu Nov 30 17:49:55 2006
+++ src/xfmedia-xine.c	Thu Nov 30 17:50:48 2006
@@ -38,14 +38,14 @@
 #ifdef HAVE_MATH_H
 #include <math.h>
 #endif
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #ifdef HAVE_SYS_SELECT_H
 #include <sys/select.h>
 #endif
 #ifdef HAVE_SYS_TIME_H
 #include <sys/time.h>
-#endif
-#ifdef HAVE_SYS_TYPES_H
-#include <sys/types.h>
 #endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>

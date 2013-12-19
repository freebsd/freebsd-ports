--- ttyload.h.orig	2013-11-24 00:51:20.729533285 +0800
+++ ttyload.h	2013-11-24 00:51:29.900534853 +0800
@@ -8,6 +8,8 @@
  *
  */
 
+#include <time.h>
+
 #define	MIN(a,b)	(((a)<(b))?(a):(b))
 #define	MAX(a,b)	(((a)>(b))?(a):(b))
 

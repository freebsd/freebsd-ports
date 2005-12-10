--- src/post/deinterlace/plugins/tomsmocomp/tomsmocompmacros.h.orig	Sat Jul 30 03:14:40 2005
+++ src/post/deinterlace/plugins/tomsmocomp/tomsmocompmacros.h	Sun Dec 11 02:54:16 2005
@@ -1,8 +1,6 @@
 #include <string.h>
 #include <math.h>
-#ifdef HAVE_MALLOC_H
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 
 #define USE_FOR_DSCALER
 

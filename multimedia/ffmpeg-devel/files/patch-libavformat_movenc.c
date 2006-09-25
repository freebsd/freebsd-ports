--- libavformat/movenc.c.orig	Wed Mar 22 16:49:05 2006
+++ libavformat/movenc.c	Wed Aug 23 12:37:33 2006
@@ -22,6 +22,10 @@
 #include "avio.h"
 #include "mov.h"
 
+#ifndef UINT32_MAX
+#define UINT32_MAX 0xffffffffU
+#endif
+
 #undef NDEBUG
 #include <assert.h>
 

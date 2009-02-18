--- libbb_udpcast.h.orig	2009-02-10 10:07:40.000000000 +0100
+++ libbb_udpcast.h	2009-02-10 10:06:51.000000000 +0100
@@ -24,6 +24,10 @@
     #include <malloc.h>
 #endif
 
+#ifdef HAVE_STDLIB_H
+    #include <stdlib.h>
+#endif
+
 #define xmalloc malloc
 
 #endif /* BB_VER */

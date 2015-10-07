--- libde265/motion.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/motion.cc	2015-07-22 17:25:26.140610000 +0200
@@ -31,7 +31,7 @@
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
-#else
+#elif defined(HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 

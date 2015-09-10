--- libde265/fallback-motion.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/fallback-motion.cc	2015-07-22 17:25:04.707534000 +0200
@@ -23,7 +23,7 @@
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
-#else
+#elif defined(HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 

--- libde265/fallback-dct.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/fallback-dct.cc	2015-07-22 17:24:55.690743000 +0200
@@ -22,7 +22,7 @@
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
-#else
+#elif defined(HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 

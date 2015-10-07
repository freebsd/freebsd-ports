--- libde265/pps.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/pps.cc	2015-07-22 17:25:38.546345000 +0200
@@ -27,7 +27,7 @@
 #include <string.h>
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
-#else
+#elif defined(HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 

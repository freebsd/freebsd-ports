--- libde265/refpic.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/refpic.cc	2015-07-22 17:25:52.916195000 +0200
@@ -26,7 +26,7 @@
 #include <stdlib.h>
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
-#else
+#elif defined(HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 

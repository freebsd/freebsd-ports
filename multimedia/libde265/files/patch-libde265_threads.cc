--- libde265/threads.cc.orig	2015-07-14 13:51:51.000000000 +0200
+++ libde265/threads.cc	2015-07-22 17:26:03.712606000 +0200
@@ -24,7 +24,7 @@
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 # include <malloc.h>
-#else
+#elif defined(HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 

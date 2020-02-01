--- include/libtorrent/tommath.h.orig	2016-08-29 10:51:22 UTC
+++ include/libtorrent/tommath.h
@@ -111,7 +111,7 @@ extern "C" {
 
 /* use arc4random on platforms that support it */
 #ifdef MP_USE_ALT_RAND
-    #define MP_GEN_RANDOM()    arc4random()
+    #define MP_GEN_RANDOM()    (int)arc4random()
 #else
     #define MP_GEN_RANDOM()    rand()
 #endif

--- src/libffmpeg/libavcodec/dsputil.c.orig	Sun Feb 18 22:17:14 2007
+++ src/libffmpeg/libavcodec/dsputil.c	Sun Feb 18 22:15:46 2007
@@ -3810,7 +3810,7 @@
     static int did_fail=0;
     DECLARE_ALIGNED_16(int, aligned);
 
-    if((int)&aligned & 15){
+    if((intptr_t)&aligned & 15){
         if(!did_fail){
 #if defined(HAVE_MMX) || defined(HAVE_ALTIVEC)
             av_log(NULL, AV_LOG_ERROR,

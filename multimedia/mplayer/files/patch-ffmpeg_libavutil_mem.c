--- ffmpeg/libavutil/mem.c.orig	2015-08-23 16:08:16 UTC
+++ ffmpeg/libavutil/mem.c
@@ -228,7 +228,7 @@ void av_free(void *ptr)
 #if CONFIG_MEMALIGN_HACK
     if (ptr) {
         int v= ((char *)ptr)[-1];
-        av_assert0(v>0 && v<=ALIGN);
+        av_assert0(v>=0 && v<=ALIGN);
         free((char *)ptr - v);
     }
 #elif HAVE_ALIGNED_MALLOC

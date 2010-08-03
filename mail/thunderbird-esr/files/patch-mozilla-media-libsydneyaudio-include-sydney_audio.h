--- mozilla/media/libsydneyaudio/include/sydney_audio.h.orgi	2009-04-10 12:24:01.000000000 +0200
+++ mozilla/media/libsydneyaudio/include/sydney_audio.h	2009-04-10 12:24:30.000000000 +0200
@@ -73,7 +73,7 @@
 #   endif
 #elif defined(WIN32)
 #   define SA_LITTLE_ENDIAN 1
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #   if defined(__BIG_ENDIAN__)
 #       define SA_BIG_ENDIAN 1
 #   else

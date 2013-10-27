--- ./lives-plugins/plugins/decoders/mkv_decoder.h.orig	2012-09-17 16:20:55.000000000 +0200
+++ ./lives-plugins/plugins/decoders/mkv_decoder.h	2013-10-14 16:49:16.000000000 +0200
@@ -262,7 +262,9 @@
     const char *native;
     const char *generic;
 };
-#if !FF_API_OLD_METADATA2
+
+#if FF_API_OLD_METADATA2
+#else
 typedef struct AVMetadataConv AVMetadataConv;
 #endif
 

--- ./kopete/protocols/wlm/wlmchatsession.cpp.orig	2012-06-03 07:53:05.000000000 -0400
+++ ./kopete/protocols/wlm/wlmchatsession.cpp	2012-06-03 07:53:42.000000000 -0400
@@ -546,13 +546,13 @@
     }
 
     if (status != GIF_OK) {
-        PrintGifError();
+        GifError();
         EGifCloseFile(GifFile);
         return;
     }
 
     if (EGifCloseFile(GifFile) != GIF_OK) {
-        PrintGifError();
+        GifError();
         return;
     }
     return;

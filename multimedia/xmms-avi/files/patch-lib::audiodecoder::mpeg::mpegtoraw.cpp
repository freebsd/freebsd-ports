--- lib/audiodecoder/mpeg/mpegtoraw.cpp.orig	Mon Nov 27 02:43:54 2000
+++ lib/audiodecoder/mpeg/mpegtoraw.cpp	Sun Dec  7 13:12:22 2003
@@ -553,8 +553,7 @@
     }
   }
 #ifdef DEBUG
-  fprintf(stderr, "MPEG %d audio layer %d (%d kbps), at %d Hz %s [%d]\n", version+1, layer,  bitrate[version][layer-1][bitrateindex], (mpeg25) ? frequencies[2][frequency] : frequencies[version][frequency], (mode == single) ? "mono" : "stere
-o", framesize);
+  fprintf(stderr, "MPEG %d audio layer %d (%d kbps), at %d Hz %s [%d]\n", version+1, layer,  bitrate[version][layer-1][bitrateindex], (mpeg25) ? frequencies[2][frequency] : frequencies[version][frequency], (mode == single) ? "mono" : "stereo", framesize);
 #endif
 
 

--- lib/mp4v2/util/mp4tags.cpp.orig	Thu Nov 11 03:16:39 2004
+++ lib/mp4v2/util/mp4tags.cpp	Thu Nov 11 03:23:05 2004
@@ -178,7 +178,7 @@
     }
     
     /* Set the other relevant attributes */
-    for (int i = 0;  i < UCHAR_MAX;  i++) {
+    for (int i = 0;  i < (int)UCHAR_MAX;  i++) {
       if (tags[i]) {
         switch(i) {
         case OPT_ALBUM:   MP4SetMetadataAlbum(h, tags[i]); break;

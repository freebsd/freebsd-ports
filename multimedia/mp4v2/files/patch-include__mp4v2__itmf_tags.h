--- ./include/mp4v2/itmf_tags.h.orig	2010-07-14 16:35:27.000000000 +0100
+++ ./include/mp4v2/itmf_tags.h	2010-07-14 16:35:35.000000000 +0100
@@ -122,7 +122,7 @@
  *  @return structure with all tags missing.
  */
 MP4V2_EXPORT
-const MP4Tags* MP4TagsAlloc();
+const MP4Tags* MP4TagsAlloc(void);
 
 /** Fetch data from mp4 file and populate structure.
  *

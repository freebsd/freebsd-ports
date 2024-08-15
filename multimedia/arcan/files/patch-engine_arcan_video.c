src/engine/arcan_video.c:1502:12: error: conflicting types for 'arcan_video_readtag'
 1502 | arcan_errc arcan_video_readtag(arcan_vobj_id id, const char** tag, const char** alt)
      |            ^
src/engine/arcan_video.h:900:18: note: previous declaration is here
  900 | arcan_errc const arcan_video_readtag(
      |                  ^

--- engine/arcan_video.c.orig	2024-07-10 23:57:57 UTC
+++ engine/arcan_video.c
@@ -1499,7 +1499,8 @@ enum arcan_transform_mask arcan_video_getmask(arcan_vo
 }
 
 
-arcan_errc arcan_video_readtag(arcan_vobj_id id, const char** tag, const char** alt)
+arcan_errc const arcan_video_readtag(
+	arcan_vobj_id id, const char** tag, const char** alt)
 {
 	arcan_vobject* vobj = arcan_video_getobject(id);
 	if (!vobj){

--- player/command.c.orig	2016-06-25 10:10:43 UTC
+++ player/command.c
@@ -2801,7 +2801,7 @@ static int mp_property_vo_performance(vo
         return M_PROPERTY_OK;
     }
 
-    struct voctrl_performance_data data = {0};
+    struct voctrl_performance_data data = {{0}};
     if (vo_control(mpctx->video_out, VOCTRL_PERFORMANCE_DATA, &data) <= 0)
         return M_PROPERTY_UNAVAILABLE;
 

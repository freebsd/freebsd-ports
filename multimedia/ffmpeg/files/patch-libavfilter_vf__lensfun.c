Partially revert https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/8b78eb312de9
until graphics/lensfun is updated to a version that contains
https://github.com/lensfun/lensfun/commit/b135e05d729d

--- libavfilter/vf_lensfun.c.orig	2021-04-08 21:28:40 UTC
+++ libavfilter/vf_lensfun.c
@@ -222,20 +222,39 @@ static int config_props(AVFilterLink *inlink)
 
     if (!lensfun->modifier) {
         if (lensfun->camera && lensfun->lens) {
-            lensfun->modifier = lf_modifier_create(lensfun->lens,
+            lensfun->modifier = lf_modifier_create(
+#if (LF_VERSION > 0x35F00)
+                                                   lensfun->lens,
                                                    lensfun->focal_length,
+#endif
                                                    lensfun->camera->CropFactor,
                                                    inlink->w,
                                                    inlink->h, LF_PF_U8, lensfun->reverse);
             if (lensfun->mode & VIGNETTING)
-                lf_modifier_enable_vignetting_correction(lensfun->modifier, lensfun->aperture, lensfun->focus_distance);
+                lf_modifier_enable_vignetting_correction(lensfun->modifier,
+#if (LF_VERSION <= 0x35F00)
+                                                         lensfun->lens, lensfun->focal_length,
+#endif
+                                                         lensfun->aperture, lensfun->focus_distance);
             if (lensfun->mode & GEOMETRY_DISTORTION) {
-                lf_modifier_enable_distortion_correction(lensfun->modifier);
-                lf_modifier_enable_projection_transform(lensfun->modifier, lensfun->target_geometry);
+                lf_modifier_enable_distortion_correction(lensfun->modifier,
+#if (LF_VERSION <= 0x35F00)
+                                                         lensfun->lens, lensfun->focal_length
+#endif
+                                                        );
+                lf_modifier_enable_projection_transform(lensfun->modifier,
+#if (LF_VERSION <= 0x35F00)
+                                                        lensfun->lens, lensfun->focal_length,
+#endif
+                                                        lensfun->target_geometry);
                 lf_modifier_enable_scaling(lensfun->modifier, lensfun->scale);
             }
             if (lensfun->mode & SUBPIXEL_DISTORTION)
-                lf_modifier_enable_tca_correction(lensfun->modifier);
+                lf_modifier_enable_tca_correction(lensfun->modifier,
+#if (LF_VERSION <= 0x35F00)
+                                                  lensfun->lens, lensfun->focal_length
+#endif
+                                                  );
         } else {
             // lensfun->camera and lensfun->lens should have been initialized
             return AVERROR_BUG;

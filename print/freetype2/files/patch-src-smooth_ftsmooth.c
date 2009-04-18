diff --git a/src/smooth/ftsmooth.c b/src/smooth/ftsmooth.c
index a6db504..cacc490 100644
--- src/smooth/ftsmooth.c
+++ src/smooth/ftsmooth.c
@@ -153,7 +153,7 @@
       slot->internal->flags &= ~FT_GLYPH_OWN_BITMAP;
     }
 
-    /* allocate new one, depends on pixel format */
+    /* allocate new one */
     pitch = width;
     if ( hmul )
     {
@@ -194,6 +194,13 @@
 
 #endif
 
+    if ( pitch > 0xFFFF || height > 0xFFFF )
+    {
+      FT_ERROR(( "ft_smooth_render_generic: glyph too large: %d x %d\n",
+                 width, height ));
+      return Smooth_Err_Raster_Overflow;
+    }
+
     bitmap->pixel_mode = FT_PIXEL_MODE_GRAY;
     bitmap->num_grays  = 256;
     bitmap->width      = width;

--- modules/codec/avcodec/vaapi.c.orig	2013-01-22 10:51:40.000000000 +0100
+++ modules/codec/avcodec/vaapi.c	2013-07-05 01:43:15.340713238 +0200
@@ -246,8 +246,8 @@
 
     /* Create surfaces */
     VASurfaceID pi_surface_id[p_va->i_surface_count];
-    if( vaCreateSurfaces( p_va->p_display, i_width, i_height, VA_RT_FORMAT_YUV420,
-                          p_va->i_surface_count, pi_surface_id ) )
+    if( vaCreateSurfaces( p_va->p_display, VA_RT_FORMAT_YUV420, i_width, i_height,
+                          pi_surface_id, p_va->i_surface_count, NULL, 0 ) )
     {
         for( int i = 0; i < p_va->i_surface_count; i++ )
             p_va->p_surface[i].i_id = VA_INVALID_SURFACE;

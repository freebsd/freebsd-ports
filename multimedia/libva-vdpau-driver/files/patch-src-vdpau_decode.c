--- src/vdpau_decode.c.orig	2012-10-05 17:02:58.000000000 +0200
+++ src/vdpau_decode.c	2014-07-02 16:01:49.966248095 +0200
@@ -1289,7 +1289,7 @@
             driver_data,
             obj_context->vdp_decoder,
             obj_surface->vdp_surface,
-            (VdpPictureInfo)&obj_context->vdp_picture_info,
+            (VdpPictureInfo *)&obj_context->vdp_picture_info,
             obj_context->vdp_bitstream_buffers_count,
             obj_context->vdp_bitstream_buffers
         );

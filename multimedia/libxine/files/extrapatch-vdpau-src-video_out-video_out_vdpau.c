--- a/src/video_out/video_out_vdpau.c
+++ b/src/video_out/video_out_vdpau.c
@@ -53,6 +53,8 @@
 
 #define NUM_FRAMES_BACK 1
 
+#define LOCKDISPLAY /*define this if you have a buggy libX11/xcb*/
+
 #define DEINT_BOB                    1
 #define DEINT_HALF_TEMPORAL          2
 #define DEINT_HALF_TEMPORAL_SPATIAL  3
@@ -167,12 +169,30 @@ static void vdpau_reinit( vo_driver_t *t
 static VdpVideoSurfaceCreate *orig_vdp_video_surface_create;
 static VdpVideoSurfaceDestroy *orig_vdp_video_surface_destroy;
 
+static VdpVideoSurfaceCreate *orig_vdp_output_surface_create;
+static VdpVideoSurfaceDestroy *orig_vdp_output_surface_destroy;
+
+static VdpVideoSurfacePutBitsYCbCr *orig_vdp_video_surface_putbits_ycbcr;
+
 static VdpDecoderCreate *orig_vdp_decoder_create;
 static VdpDecoderDestroy *orig_vdp_decoder_destroy;
 static VdpDecoderRender *orig_vdp_decoder_render;
 
 static Display *guarded_display;
 
+static VdpStatus guarded_vdp_video_surface_putbits_ycbcr(VdpVideoSurface surface, VdpYCbCrFormat source_ycbcr_format, void const *const *source_data, uint32_t const *source_pitches)
+{
+  VdpStatus r;
+#ifdef LOCKDISPLAY
+  XLockDisplay(guarded_display);
+#endif
+  r = orig_vdp_video_surface_putbits_ycbcr(surface, source_ycbcr_format, source_data, source_pitches);
+#ifdef LOCKDISPLAY
+  XUnlockDisplay(guarded_display);
+#endif
+  return r;
+}
+
 static VdpStatus guarded_vdp_video_surface_create(VdpDevice device, VdpChromaType chroma_type, uint32_t width, uint32_t height,VdpVideoSurface *surface)
 {
   VdpStatus r;
@@ -195,6 +215,28 @@ static VdpStatus guarded_vdp_video_surfa
   return r;
 }
 
+static VdpStatus guarded_vdp_output_surface_create(VdpDevice device, VdpChromaType chroma_type, uint32_t width, uint32_t height,VdpVideoSurface *surface)
+{
+  VdpStatus r;
+#ifdef LOCKDISPLAY
+  XLockDisplay(guarded_display);
+#endif
+  r = orig_vdp_output_surface_create(device, chroma_type, width, height, surface);
+#ifdef LOCKDISPLAY
+  XUnlockDisplay(guarded_display);
+#endif
+  return r;
+}
+
+static VdpStatus guarded_vdp_output_surface_destroy(VdpVideoSurface surface)
+{
+  VdpStatus r;
+  XLockDisplay(guarded_display);
+  r = orig_vdp_output_surface_destroy(surface);
+  XUnlockDisplay(guarded_display);
+  return r;
+}
+
 static VdpStatus guarded_vdp_decoder_create(VdpDevice device, VdpDecoderProfile profile, uint32_t width, uint32_t height, uint32_t max_references, VdpDecoder *decoder)
 {
   VdpStatus r;
@@ -2324,16 +2366,16 @@ static vo_driver_t *vdpau_open_plugin (v
   st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_VIDEO_SURFACE_DESTROY , (void*)&orig_vdp_video_surface_destroy ); vdp_video_surface_destroy = guarded_vdp_video_surface_destroy;
   if ( vdpau_init_error( st, "Can't get VIDEO_SURFACE_DESTROY proc address !!", &this->vo_driver, 1 ) )
     return NULL;
-  st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_VIDEO_SURFACE_PUT_BITS_Y_CB_CR , (void*)&vdp_video_surface_putbits_ycbcr );
+  st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_VIDEO_SURFACE_PUT_BITS_Y_CB_CR , (void*)&orig_vdp_video_surface_putbits_ycbcr ); vdp_video_surface_putbits_ycbcr = guarded_vdp_video_surface_putbits_ycbcr;
   if ( vdpau_init_error( st, "Can't get VIDEO_SURFACE_PUT_BITS_Y_CB_CR proc address !!", &this->vo_driver, 1 ) )
     return NULL;
   st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_VIDEO_SURFACE_GET_BITS_Y_CB_CR , (void*)&vdp_video_surface_getbits_ycbcr );
   if ( vdpau_init_error( st, "Can't get VIDEO_SURFACE_GET_BITS_Y_CB_CR proc address !!", &this->vo_driver, 1 ) )
     return NULL;
-  st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_OUTPUT_SURFACE_CREATE , (void*)&vdp_output_surface_create );
+  st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_OUTPUT_SURFACE_CREATE , (void*)&orig_vdp_output_surface_create ); vdp_output_surface_create = guarded_vdp_output_surface_create;
   if ( vdpau_init_error( st, "Can't get OUTPUT_SURFACE_CREATE proc address !!", &this->vo_driver, 1 ) )
     return NULL;
-  st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_OUTPUT_SURFACE_DESTROY , (void*)&vdp_output_surface_destroy );
+  st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_OUTPUT_SURFACE_DESTROY , (void*)&orig_vdp_output_surface_destroy ); vdp_output_surface_destroy = guarded_vdp_output_surface_destroy;
   if ( vdpau_init_error( st, "Can't get OUTPUT_SURFACE_DESTROY proc address !!", &this->vo_driver, 1 ) )
     return NULL;
   st = vdp_get_proc_address( vdp_device, VDP_FUNC_ID_OUTPUT_SURFACE_RENDER_BITMAP_SURFACE , (void*)&vdp_output_surface_render_bitmap_surface );

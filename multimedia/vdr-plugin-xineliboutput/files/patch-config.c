--- a/config.c
+++ b/config.c
@@ -544,7 +544,11 @@ config_t::config_t() {
   memset(audio_equalizer,0,sizeof(audio_equalizer));
   strn0cpy(audio_visualization, "goom", sizeof(audio_visualization));
   strn0cpy(audio_vis_goom_opts, "fps:25,width:720,height:576", sizeof(audio_vis_goom_opts));
+#ifdef LOCALBASE
+  strn0cpy(audio_vis_image_mrl, "file:" LOCALBASE "/share/xine/visuals/default.avi", sizeof(audio_vis_image_mrl));
+#else
   strn0cpy(audio_vis_image_mrl, "file:/usr/share/xine/visuals/default.avi", sizeof(audio_vis_image_mrl));
+#endif
 
   headphone = 0;
   audio_upmix = 0;

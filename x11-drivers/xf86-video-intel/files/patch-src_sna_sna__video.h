--- src/sna/sna_video.h.orig	2015-03-05 09:53:01 UTC
+++ src/sna/sna_video.h
@@ -129,6 +129,7 @@ void sna_video_overlay_setup(struct sna 
 void sna_video_sprite_setup(struct sna *sna, ScreenPtr screen);
 void sna_video_textured_setup(struct sna *sna, ScreenPtr screen);
 void sna_video_destroy_window(WindowPtr win);
+void sna_video_close(struct sna *sna);
 
 XvAdaptorPtr sna_xv_adaptor_alloc(struct sna *sna);
 int sna_xv_fixup_formats(ScreenPtr screen,

--- src/rip_audio.h.orig	2000-12-11 18:26:41 UTC
+++ src/rip_audio.h
@@ -20,4 +20,3 @@ void open_rip_audio_req(void);
 
 extern char *cdda2wav_path, *cdda_device_path, *cdparanoia_path;
 extern char *def_rip_path;
-extern GtkWidget *rip_path_entry;

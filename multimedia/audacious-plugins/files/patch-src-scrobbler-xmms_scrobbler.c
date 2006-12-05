--- src/scrobbler/xmms_scrobbler.c.orig	Mon Dec  4 16:14:52 2006
+++ src/scrobbler/xmms_scrobbler.c	Tue Dec  5 06:21:00 2006
@@ -60,8 +60,9 @@
 {
 	char *username = NULL, *password = NULL;
 	ConfigDb *cfgfile;
-	going = 1;
 	GError **moo = NULL;
+
+	going = 1;
 	cfgdlg = create_cfgdlg();
 
         prefswin_page_new(cfgdlg, "Last.FM", DATA_DIR "/images/audioscrobbler.png");

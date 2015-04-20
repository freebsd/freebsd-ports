--- src/sna/sna_video.c.orig	2015-03-05 09:45:32 UTC
+++ src/sna/sna_video.c
@@ -68,6 +68,7 @@
 #else
 static inline void sna_video_xvmc_setup(struct sna *sna, ScreenPtr ptr)
 {
+	DBG(("%s: XvMC not compiled in\n"));
 }
 #endif
 
@@ -620,6 +621,7 @@ sna_xv_fixup_formats(ScreenPtr screen, X
 	return count;
 }
 
+#if XORG_XV_VERSION < 2
 static int
 sna_xv_query_adaptors(ScreenPtr screen,
 		      XvAdaptorPtr *adaptors,
@@ -636,20 +638,10 @@ static Bool
 sna_xv_close_screen(CLOSE_SCREEN_ARGS_DECL)
 {
 	struct sna *sna = to_sna_from_screen(screen);
-	int i;
-
-	for (i = 0; i < sna->xv.num_adaptors; i++) {
-		free(sna->xv.adaptors[i].pPorts->devPriv.ptr);
-		free(sna->xv.adaptors[i].pPorts);
-		free(sna->xv.adaptors[i].pEncodings);
-	}
-	free(sna->xv.adaptors);
-
-	sna->xv.adaptors = NULL;
-	sna->xv.num_adaptors = 0;
-
+	sna_video_close(sna);
 	return TRUE;
 }
+#endif
 
 void sna_video_init(struct sna *sna, ScreenPtr screen)
 {
@@ -671,8 +663,10 @@ void sna_video_init(struct sna *sna, Scr
 		return;
 
 	xv = to_xv(screen);
+#if XORG_XV_VERSION < 2
 	xv->ddCloseScreen = sna_xv_close_screen;
 	xv->ddQueryAdaptors = sna_xv_query_adaptors;
+#endif
 
 	sna_video_textured_setup(sna, screen);
 	sna_video_sprite_setup(sna, screen);
@@ -698,7 +692,28 @@ void sna_video_destroy_window(WindowPtr 
 	XvPortPtr port;
 
 	port = sna_window_get_port(win);
-	if (port)
+	if (port) {
+#if XORG_XV_VERSION < 2
 		port->pAdaptor->ddStopVideo(NULL, port, &win->drawable);
+#else
+		port->pAdaptor->ddStopVideo(port, &win->drawable);
+#endif
+	}
 	assert(sna_window_get_port(win) == NULL);
 }
+
+void sna_video_close(struct sna *sna)
+{
+	int i;
+
+	for (i = 0; i < sna->xv.num_adaptors; i++) {
+		free(sna->xv.adaptors[i].pPorts->devPriv.ptr);
+		free(sna->xv.adaptors[i].pPorts);
+		free(sna->xv.adaptors[i].pEncodings);
+	}
+	free(sna->xv.adaptors);
+
+	sna->xv.adaptors = NULL;
+	sna->xv.num_adaptors = 0;
+}
+

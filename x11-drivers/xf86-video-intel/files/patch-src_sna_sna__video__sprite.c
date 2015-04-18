--- src/sna/sna_video_sprite.c.orig	2015-03-05 10:02:08 UTC
+++ src/sna/sna_video_sprite.c
@@ -56,9 +56,7 @@ static const XvAttributeRec attribs[] = 
 	{ XvSettable | XvGettable, 0, 0xffffff, (char *)"XV_COLORKEY" },
 };
 
-static int sna_video_sprite_stop(ClientPtr client,
-				 XvPortPtr port,
-				 DrawablePtr draw)
+static int sna_video_sprite_stop(ddStopVideo_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct drm_mode_set_plane s;
@@ -82,10 +80,7 @@ static int sna_video_sprite_stop(ClientP
 	return Success;
 }
 
-static int sna_video_sprite_set_attr(ClientPtr client,
-				     XvPortPtr port,
-				     Atom attribute,
-				     INT32 value)
+static int sna_video_sprite_set_attr(ddSetPortAttribute_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 
@@ -104,10 +99,7 @@ static int sna_video_sprite_set_attr(Cli
 	return Success;
 }
 
-static int sna_video_sprite_get_attr(ClientPtr client,
-				     XvPortPtr port,
-				     Atom attribute,
-				     INT32 *value)
+static int sna_video_sprite_get_attr(ddGetPortAttribute_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 
@@ -121,13 +113,7 @@ static int sna_video_sprite_get_attr(Cli
 	return Success;
 }
 
-static int sna_video_sprite_best_size(ClientPtr client,
-				      XvPortPtr port,
-				      CARD8 motion,
-				      CARD16 vid_w, CARD16 vid_h,
-				      CARD16 drw_w, CARD16 drw_h,
-				      unsigned int *p_w,
-				      unsigned int *p_h)
+static int sna_video_sprite_best_size(ddQueryBestSize_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -310,18 +296,7 @@ sna_video_sprite_show(struct sna *sna,
 	return true;
 }
 
-static int sna_video_sprite_put_image(ClientPtr client,
-				      DrawablePtr draw,
-				      XvPortPtr port,
-				      GCPtr gc,
-				      INT16 src_x, INT16 src_y,
-				      CARD16 src_w, CARD16 src_h,
-				      INT16 drw_x, INT16 drw_y,
-				      CARD16 drw_w, CARD16 drw_h,
-				      XvImagePtr format,
-				      unsigned char *buf,
-				      Bool sync,
-				      CARD16 width, CARD16 height)
+static int sna_video_sprite_put_image(ddPutImage_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -430,16 +405,14 @@ static int sna_video_sprite_put_image(Cl
 
 invisible:
 	/* If the video isn't visible on any CRTC, turn it off */
+#if XORG_XV_VERSION < 2
 	return sna_video_sprite_stop(client, port, draw);
+#else
+	return sna_video_sprite_stop(port, draw);
+#endif
 }
 
-static int sna_video_sprite_query(ClientPtr client,
-				  XvPortPtr port,
-				  XvImagePtr format,
-				  unsigned short *w,
-				  unsigned short *h,
-				  int *pitches,
-				  int *offsets)
+static int sna_video_sprite_query(ddQueryImageAttributes_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna_video_frame frame;
@@ -548,8 +521,10 @@ void sna_video_sprite_setup(struct sna *
 	if (sna->kgem.gen == 071)
 		adaptor->nImages = 4;
 
+#if XORG_XV_VERSION < 2
 	adaptor->ddAllocatePort = sna_xv_alloc_port;
 	adaptor->ddFreePort = sna_xv_free_port;
+#endif
 	adaptor->ddPutVideo = NULL;
 	adaptor->ddPutStill = NULL;
 	adaptor->ddGetVideo = NULL;
@@ -593,6 +568,8 @@ void sna_video_sprite_setup(struct sna *
 
 	xvColorKey = MAKE_ATOM("XV_COLORKEY");
 	xvAlwaysOnTop = MAKE_ATOM("XV_ALWAYS_ON_TOP");
+
+	DBG(("%s: '%s' initialized %d ports\n", __FUNCTION__, adaptor->name, adaptor->nPorts));
 }
 #else
 void sna_video_sprite_setup(struct sna *sna, ScreenPtr screen)

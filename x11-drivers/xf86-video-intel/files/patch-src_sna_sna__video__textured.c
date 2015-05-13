--- src/sna/sna_video_textured.c.orig	2015-03-05 10:08:42 UTC
+++ src/sna/sna_video_textured.c
@@ -56,9 +56,7 @@ static const XvImageRec Images[] = {
 	XVMC_YUV,
 };
 
-static int sna_video_textured_stop(ClientPtr client,
-				   XvPortPtr port,
-				   DrawablePtr draw)
+static int sna_video_textured_stop(ddStopVideo_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 
@@ -71,10 +69,7 @@ static int sna_video_textured_stop(Clien
 }
 
 static int
-sna_video_textured_set_attribute(ClientPtr client,
-				 XvPortPtr port,
-				 Atom attribute,
-				 INT32 value)
+sna_video_textured_set_attribute(ddSetPortAttribute_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 
@@ -100,10 +95,7 @@ sna_video_textured_set_attribute(ClientP
 }
 
 static int
-sna_video_textured_get_attribute(ClientPtr client,
-				 XvPortPtr port,
-				 Atom attribute,
-				 INT32 *value)
+sna_video_textured_get_attribute(ddGetPortAttribute_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 
@@ -120,13 +112,7 @@ sna_video_textured_get_attribute(ClientP
 }
 
 static int
-sna_video_textured_best_size(ClientPtr client,
-			     XvPortPtr port,
-			     CARD8 motion,
-			     CARD16 vid_w, CARD16 vid_h,
-			     CARD16 drw_w, CARD16 drw_h,
-			     unsigned int *p_w,
-			     unsigned int *p_h)
+sna_video_textured_best_size(ddQueryBestSize_ARGS)
 {
 	if (vid_w > (drw_w << 1))
 		drw_w = vid_w >> 1;
@@ -153,18 +139,7 @@ sna_video_textured_best_size(ClientPtr c
  * compositing.  It's a new argument to the function in the 1.1 server.
  */
 static int
-sna_video_textured_put_image(ClientPtr client,
-			     DrawablePtr draw,
-			     XvPortPtr port,
-			     GCPtr gc,
-			     INT16 src_x, INT16 src_y,
-			     CARD16 src_w, CARD16 src_h,
-			     INT16 drw_x, INT16 drw_y,
-			     CARD16 drw_w, CARD16 drw_h,
-			     XvImagePtr format,
-			     unsigned char *buf,
-			     Bool sync,
-			     CARD16 width, CARD16 height)
+sna_video_textured_put_image(ddPutImage_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -269,13 +244,7 @@ sna_video_textured_put_image(ClientPtr c
 }
 
 static int
-sna_video_textured_query(ClientPtr client,
-			 XvPortPtr port,
-			 XvImagePtr format,
-			 unsigned short *w,
-			 unsigned short *h,
-			 int *pitches,
-			 int *offsets)
+sna_video_textured_query(ddQueryImageAttributes_ARGS)
 {
 	int size, tmp;
 
@@ -384,8 +353,10 @@ void sna_video_textured_setup(struct sna
 	adaptor->pAttributes = (XvAttributeRec *)Attributes;
 	adaptor->nImages = ARRAY_SIZE(Images);
 	adaptor->pImages = (XvImageRec *)Images;
+#if XORG_XV_VERSION < 2
 	adaptor->ddAllocatePort = sna_xv_alloc_port;
 	adaptor->ddFreePort = sna_xv_free_port;
+#endif
 	adaptor->ddPutVideo = NULL;
 	adaptor->ddPutStill = NULL;
 	adaptor->ddGetVideo = NULL;
@@ -426,4 +397,6 @@ void sna_video_textured_setup(struct sna
 	xvBrightness = MAKE_ATOM("XV_BRIGHTNESS");
 	xvContrast = MAKE_ATOM("XV_CONTRAST");
 	xvSyncToVblank = MAKE_ATOM("XV_SYNC_TO_VBLANK");
+
+	DBG(("%s: '%s' initialized %d ports\n", __FUNCTION__, adaptor->name, adaptor->nPorts));
 }

--- src/sna/sna_video_overlay.c.orig	2015-03-05 09:54:32 UTC
+++ src/sna/sna_video_overlay.c
@@ -121,9 +121,7 @@ static bool sna_video_overlay_update_att
 	return drmIoctl(video->sna->kgem.fd, DRM_IOCTL_I915_OVERLAY_ATTRS, &attrs) == 0;
 }
 
-static int sna_video_overlay_stop(ClientPtr client,
-				  XvPortPtr port,
-				  DrawablePtr draw)
+static int sna_video_overlay_stop(ddStopVideo_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -148,10 +146,7 @@ static int sna_video_overlay_stop(Client
 }
 
 static int
-sna_video_overlay_set_attribute(ClientPtr client,
-				XvPortPtr port,
-				Atom attribute,
-				INT32 value)
+sna_video_overlay_set_attribute(ddSetPortAttribute_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -270,12 +265,7 @@ sna_video_overlay_get_attribute(ClientPt
 }
 
 static int
-sna_video_overlay_best_size(ClientPtr client,
-			    XvPortPtr port,
-			    CARD8 motion,
-			    CARD16 vid_w, CARD16 vid_h,
-			    CARD16 drw_w, CARD16 drw_h,
-			    unsigned int *p_w, unsigned int *p_h)
+sna_video_overlay_best_size(ddQueryBestSize_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -464,18 +454,7 @@ sna_video_overlay_show(struct sna *sna,
 }
 
 static int
-sna_video_overlay_put_image(ClientPtr client,
-			    DrawablePtr draw,
-			    XvPortPtr port,
-			    GCPtr gc,
-			    INT16 src_x, INT16 src_y,
-			    CARD16 src_w, CARD16 src_h,
-			    INT16 drw_x, INT16 drw_y,
-			    CARD16 drw_w, CARD16 drw_h,
-			    XvImagePtr format,
-			    unsigned char *buf,
-			    Bool sync,
-			    CARD16 width, CARD16 height)
+sna_video_overlay_put_image(ddPutImage_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna *sna = video->sna;
@@ -604,18 +583,16 @@ invisible:
 	/*
 	 * If the video isn't visible on any CRTC, turn it off
 	 */
+#if XORG_XV_VERSION < 2
 	sna_video_overlay_stop(client, port, draw);
+#else
+	sna_video_overlay_stop(port, draw);
+#endif
 	return Success;
 }
 
 static int
-sna_video_overlay_query(ClientPtr client,
-			XvPortPtr port,
-			XvImagePtr format,
-			unsigned short *w,
-			unsigned short *h,
-			int *pitches,
-			int *offsets)
+sna_video_overlay_query(ddQueryImageAttributes_ARGS)
 {
 	struct sna_video *video = port->devPriv.ptr;
 	struct sna_video_frame frame;
@@ -771,8 +748,10 @@ void sna_video_overlay_setup(struct sna 
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
@@ -843,4 +822,6 @@ void sna_video_overlay_setup(struct sna 
 	}
 
 	sna_video_overlay_update_attrs(video);
+
+	DBG(("%s: '%s' initialized %d ports\n", __FUNCTION__, adaptor->name, adaptor->nPorts));
 }

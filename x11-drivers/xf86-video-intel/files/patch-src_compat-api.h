--- src/compat-api.h.orig	2013-05-21 10:15:11 UTC
+++ src/compat-api.h
@@ -158,4 +158,40 @@ static inline void FreePixmap(PixmapPtr 
 	if ((d)->pScreen->SourceValidate) (d)->pScreen->SourceValidate(d, x, y, w, h)
 #endif
 
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(1,14,99,2,0)
+#define DamageUnregister(d, dd) DamageUnregister(dd)
+#endif
+
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(1,16,99,1,0)
+
+#define XORG_XV_VERSION 2
+#define ddStopVideo_ARGS XvPortPtr port, DrawablePtr draw
+#define ddSetPortAttribute_ARGS XvPortPtr port, Atom attribute, INT32 value
+#define ddGetPortAttribute_ARGS XvPortPtr port, Atom attribute, INT32 *value
+#define ddQueryBestSize_ARGS XvPortPtr port, CARD8 motion, CARD16 vid_w, CARD16 vid_h, CARD16 drw_w, CARD16 drw_h, unsigned int *p_w, unsigned int *p_h
+#define ddPutImage_ARGS DrawablePtr draw, XvPortPtr port, GCPtr gc, INT16 src_x, INT16 src_y, CARD16 src_w, CARD16 src_h, INT16 drw_x, INT16 drw_y, CARD16 drw_w, CARD16 drw_h, XvImagePtr format, unsigned char *buf, Bool sync, CARD16 width, CARD16 height
+#define ddQueryImageAttributes_ARGS XvPortPtr port, XvImagePtr format, unsigned short *w, unsigned short *h, int *pitches, int *offsets
+
+#else
+
+#define XORG_XV_VERSION 1
+#define ddStopVideo_ARGS ClientPtr client, XvPortPtr port, DrawablePtr draw
+#define ddSetPortAttribute_ARGS ClientPtr client, XvPortPtr port, Atom attribute, INT32 value
+#define ddGetPortAttribute_ARGS ClientPtr client, XvPortPtr port, Atom attribute, INT32 *value
+#define ddQueryBestSize_ARGS ClientPtr client, XvPortPtr port, CARD8 motion, CARD16 vid_w, CARD16 vid_h, CARD16 drw_w, CARD16 drw_h, unsigned int *p_w, unsigned int *p_h
+#define ddPutImage_ARGS ClientPtr client, DrawablePtr draw, XvPortPtr port, GCPtr gc, INT16 src_x, INT16 src_y, CARD16 src_w, CARD16 src_h, INT16 drw_x, INT16 drw_y, CARD16 drw_w, CARD16 drw_h, XvImagePtr format, unsigned char *buf, Bool sync, CARD16 width, CARD16 height
+#define ddQueryImageAttributes_ARGS ClientPtr client, XvPortPtr port, XvImagePtr format, unsigned short *w, unsigned short *h, int *pitches, int *offsets
+
+#endif
+
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(1,16,99,1,0)
+#include <mi.h>
+#define miHandleExposures(pSrcDrawable, pDstDrawable, \
+			  pGC, srcx, srcy, width, height, \
+			  dstx, dsty, plane) \
+	miHandleExposures(pSrcDrawable, pDstDrawable, \
+			  pGC, srcx, srcy, width, height, \
+			  dstx, dsty)
+#endif
+
 #endif

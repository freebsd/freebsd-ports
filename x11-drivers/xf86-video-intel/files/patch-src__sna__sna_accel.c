--- src/sna/sna_accel.c.orig	2013-08-20 20:26:26 UTC
+++ src/sna/sna_accel.c
@@ -3797,6 +3797,7 @@ static bool must_check sna_gc_move_to_cp
 	sgc->priv = gc->pCompositeClip;
 	gc->pCompositeClip = region;
 
+#if XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(1,16,99,901,0)
 	if (gc->clientClipType == CT_PIXMAP) {
 		PixmapPtr clip = gc->clientClip;
 		gc->clientClip = region_from_bitmap(gc->pScreen, clip);
@@ -3804,7 +3805,9 @@ static bool must_check sna_gc_move_to_cp
 		gc->clientClipType = gc->clientClip ? CT_REGION : CT_NONE;
 		changes |= GCClipMask;
 	} else
+#else
 		changes &= ~GCClipMask;
+#endif
 
 	if (changes || drawable->serialNumber != sgc->serial) {
 		gc->serialNumber = sgc->serial;
@@ -5562,6 +5565,15 @@ static inline bool box_equal(const BoxRe
 	return *(const uint64_t *)a == *(const uint64_t *)b;
 }
 
+static inline bool has_clip(GCPtr gc)
+{
+#if XORG_VERSION_CURRENT < XORG_VERSION_NUMERIC(1,16,99,901,0)
+	return gc->clientClipType != CT_NONE;
+#else
+	return gc->clientClip != NULL;
+#endif
+}
+
 static RegionPtr
 sna_do_copy(DrawablePtr src, DrawablePtr dst, GCPtr gc,
 	    int sx, int sy,
@@ -5628,7 +5640,7 @@ sna_do_copy(DrawablePtr src, DrawablePtr
 
 	/* Compute source clip region */
 	if (src->type == DRAWABLE_PIXMAP) {
-		if (src == dst && gc->clientClipType == CT_NONE) {
+		if (src == dst && !has_clip(gc)) {
 			DBG(("%s: pixmap -- using gc clip\n", __FUNCTION__));
 			clip = gc->pCompositeClip;
 		} else {
@@ -14391,7 +14403,7 @@ sna_validate_gc(GCPtr gc, unsigned long 
 
 	if (changes & (GCClipMask|GCSubwindowMode) ||
 	    drawable->serialNumber != (gc->serialNumber & DRAWABLE_SERIAL_BITS) ||
-	    (gc->clientClipType != CT_NONE && (changes & (GCClipXOrigin | GCClipYOrigin))))
+	    (has_clip(gc) && (changes & (GCClipXOrigin | GCClipYOrigin))))
 		miComputeCompositeClip(gc, drawable);
 
 	sna_gc(gc)->changes |= changes;
@@ -14830,7 +14842,7 @@ static bool has_offload_slaves(struct sn
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == sna->front);
@@ -14987,7 +14999,7 @@ static void sna_accel_post_damage(struct
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 	bool flush = false;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
@@ -15216,7 +15228,7 @@ migrate_dirty_tracking(PixmapPtr old_fro
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = old_front->drawable.pScreen;
-	PixmapDirtyUpdatePtr dirty, safe;
+	PixmapDirtyUpdatePtr dirty = NULL, safe;
 
 	xorg_list_for_each_entry_safe(dirty, safe, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == old_front);

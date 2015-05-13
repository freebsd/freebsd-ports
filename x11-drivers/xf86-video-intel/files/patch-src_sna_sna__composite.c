--- src/sna/sna_composite.c.orig	2013-08-14 11:59:36 UTC
+++ src/sna/sna_composite.c
@@ -122,11 +122,21 @@ clip_to_dst(pixman_region16_t *region,
 }
 
 static inline bool
+picture_has_clip(PicturePtr p)
+{
+#if XORG_VERSION_CURRENT >= XORG_VERSION_NUMERIC(1,16,99,1,0)
+	return p->clientClip;
+#else
+	return p->clientClipType != CT_NONE;
+#endif
+}
+
+static inline bool
 clip_to_src(RegionPtr region, PicturePtr p, int dx, int	 dy)
 {
 	bool result;
 
-	if (p->clientClipType == CT_NONE)
+	if (!picture_has_clip(p))
 		return true;
 
 	pixman_region_translate(p->clientClip,
@@ -220,7 +230,7 @@ sna_compute_composite_region(RegionPtr r
 		       __FUNCTION__,
 		       src->pDrawable ? src->pDrawable->width : 0,
 		       src->pDrawable ? src->pDrawable->height : 0,
-		       src->clientClipType,
+		       picture_has_clip(src),
 		       region->extents.x1, region->extents.y1,
 		       region->extents.x2, region->extents.y2));
 
@@ -287,7 +297,7 @@ trim_extents(BoxPtr extents, const Pictu
 static void
 _trim_source_extents(BoxPtr extents, const PicturePtr p, int dx, int dy)
 {
-	if (p->clientClipType != CT_NONE)
+	if (picture_has_clip(p))
 		trim_extents(extents, p, dx, dy);
 }
 

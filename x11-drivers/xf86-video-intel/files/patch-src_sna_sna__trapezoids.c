From 48a33fc379b17eed195875222ad773c911d9dff1 Mon Sep 17 00:00:00 2001
From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Tue, 2 Sep 2014 19:08:36 +0100
Subject: sna/trapezoids: Use the corrected trapezoid origin for aligned boxes

The rule for the origin of the CompositeTrapezoids routine is the
upper-left corner of the first trapezoid. Care must be taken in case the
trapezoid edge is upside down to consider the upper vertex.

Reported-by: "Jasper St. Pierre" <jstpierre@mecheye.net>
Signed-off-by: Chris Wilson <chris@chris-wilson.co.uk>


--- src/sna/sna_trapezoids.c.orig	2013-08-20 22:26:26.000000000 +0200
+++ src/sna/sna_trapezoids.c	2015-04-12 16:40:02.382938000 +0200
@@ -2690,13 +2690,16 @@
 	BoxRec stack_boxes[64], *boxes;
 	pixman_region16_t region, clip;
 	struct sna_composite_op tmp;
+	int16_t dst_x, dst_y;
 	bool ret = true;
 	int dx, dy, n, num_boxes;
 
 	if (NO_ALIGNED_BOXES)
 		return false;
 
-	DBG(("%s\n", __FUNCTION__));
+	DBG(("%s: pixmap=%ld, nboxes=%d, dx=(%d, %d)\n", __FUNCTION__,
+	    get_drawable_pixmap(dst->pDrawable)->drawable.serialNumber,
+	    ntrap, dst->pDrawable->x, dst->pDrawable->y));
 
 	boxes = stack_boxes;
 	if (ntrap > (int)ARRAY_SIZE(stack_boxes)) {
@@ -2738,19 +2741,20 @@
 	if (num_boxes == 0)
 		goto free_boxes;
 
-	DBG(("%s: extents (%d, %d), (%d, %d) offset of (%d, %d)\n",
+	trapezoid_origin(&traps[0].left, &dst_x, &dst_y);
+
+	DBG(("%s: extents (%d, %d), (%d, %d) offset of (%d, %d), origin (%d, %d)\n",
 	     __FUNCTION__,
 	     region.extents.x1, region.extents.y1,
 	     region.extents.x2, region.extents.y2,
 	     region.extents.x1 - boxes[0].x1,
-	     region.extents.y1 - boxes[0].y1));
-
-	src_x += region.extents.x1 - boxes[0].x1;
-	src_y += region.extents.y1 - boxes[0].y1;
+	     region.extents.y1 - boxes[0].y1,
+	     dst_x, dst_y));
 
 	if (!sna_compute_composite_region(&clip,
 					  src, NULL, dst,
-					  src_x,  src_y,
+					  src_x + region.extents.x1 - dst_x - dx,
+					  src_y + region.extents.y1 - dst_y - dy,
 					  0, 0,
 					  region.extents.x1 - dx, region.extents.y1 - dy,
 					  region.extents.x2 - region.extents.x1,
@@ -2760,9 +2764,18 @@
 		goto done;
 	}
 
+	DBG(("%s: clipped extents (%d, %d), (%d, %d);  now offset by (%d, %d), orgin (%d, %d)\n",
+	    __FUNCTION__,
+	     clip.extents.x1, clip.extents.y1,
+	     clip.extents.x2, clip.extents.y2,
+	     clip.extents.x1 - boxes[0].x1,
+	     clip.extents.y1 - boxes[0].y1,
+	     dst_x, dst_y));
+
 	if (force_fallback ||
 	    !sna->render.composite(sna, op, src, NULL, dst,
-				   src_x,  src_y,
+				   src_x + clip.extents.x1 - dst_x,
+				   src_y + clip.extents.y1 - dst_y,
 				   0, 0,
 				   clip.extents.x1,  clip.extents.y1,
 				   clip.extents.x2 - clip.extents.x1,
@@ -2796,6 +2809,8 @@
 		}
 
 		DBG(("%s: fbComposite()\n", __FUNCTION__));
+		src_x -= dst_x - dx;
+		src_y -= dst_y - dy;
 		if (maskFormat) {
 			pixman_region_init_rects(&region, boxes, num_boxes);
 			RegionIntersect(&region, &region, &clip);
@@ -2804,8 +2819,8 @@
 			count = REGION_NUM_RECTS(&region);
 			for (i = 0; i < count; i++) {
 				fbComposite(op, src, NULL, dst,
-					    src_x + b[i].x1 - boxes[0].x1,
-					    src_y + b[i].y1 - boxes[0].y1,
+					    src_x + b[i].x1,
+					    src_y + b[i].y1,
 					    0, 0,
 					    b[i].x1, b[i].y1,
 					    b[i].x2 - b[i].x1, b[i].y2 - b[i].y1);
@@ -2819,8 +2834,8 @@
 				count = REGION_NUM_RECTS(&region);
 				for (i = 0; i < count; i++) {
 					fbComposite(op, src, NULL, dst,
-						    src_x + b[i].x1 - boxes[0].x1,
-						    src_y + b[i].y1 - boxes[0].y1,
+						    src_x + b[i].x1,
+						    src_y + b[i].y1,
 						    0, 0,
 						    b[i].x1, b[i].y1,
 						    b[i].x2 - b[i].x1, b[i].y2 - b[i].y1);

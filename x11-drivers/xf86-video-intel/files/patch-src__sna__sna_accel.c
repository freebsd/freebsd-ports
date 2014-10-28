--- src/sna/sna_accel.c.orig	2014-10-28 00:26:56.720761613 +0100
+++ src/sna/sna_accel.c	2014-10-28 00:28:12.783756153 +0100
@@ -14830,7 +14830,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == sna->front);
@@ -14987,7 +14987,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = sna->scrn->pScreen;
-	PixmapDirtyUpdatePtr dirty;
+	PixmapDirtyUpdatePtr dirty = NULL;
 	bool flush = false;
 
 	xorg_list_for_each_entry(dirty, &screen->pixmap_dirty_list, ent) {
@@ -15216,7 +15216,7 @@
 {
 #if HAS_PIXMAP_SHARING
 	ScreenPtr screen = old_front->drawable.pScreen;
-	PixmapDirtyUpdatePtr dirty, safe;
+	PixmapDirtyUpdatePtr dirty = NULL, safe;
 
 	xorg_list_for_each_entry_safe(dirty, safe, &screen->pixmap_dirty_list, ent) {
 		assert(dirty->src == old_front);

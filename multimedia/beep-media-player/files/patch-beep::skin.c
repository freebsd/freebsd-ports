--- beep/skin.c.orig	Sat Feb  7 17:42:34 2004
+++ beep/skin.c	Sat Feb  7 17:46:18 2004
@@ -168,6 +168,7 @@
     const SMID_Mapping *sm_inf;
     GdkPixmap *gpm;
     gboolean retval = FALSE;
+	SkinPixmap *pm;
 
     if (id >= SKIN_PMID_LAST) {
 	g_warning("skin pixmap id out of range (%u).", id);
@@ -201,7 +202,7 @@
     }
     g_free(tmpstr);
 
-    SkinPixmap *pm = &sk->pixmaps[id];
+    pm = &sk->pixmaps[id];
     gpm = read_bmp(filename);
 
     if (!gpm) {
@@ -733,9 +734,9 @@
 GdkBitmap *skin_get_mask(MaskIndex mi, gboolean doublesize,
 			 gboolean shaded)
 {
+	GdkBitmap **masks;
     g_assert(skin != NULL);
 
-    GdkBitmap **masks;
 
     g_assert(mi < SKIN_MID_LAST);
     masks = (doublesize ? skin->ds_masks : skin->masks);
@@ -813,8 +814,10 @@
     gint i;
     GdkPixmap *pixmap;
     GdkImage *img;
+	SkinPixmap *eqmainpm;
+
     g_assert(skin != NULL);
-    SkinPixmap *eqmainpm = &skin->pixmaps[SKIN_EQMAIN];
+    eqmainpm = &skin->pixmaps[SKIN_EQMAIN];
     if (eqmainpm->pixmap != NULL &&
 	eqmainpm->current_width >= 116 && eqmainpm->current_height >= 313)
 	pixmap = eqmainpm->pixmap;

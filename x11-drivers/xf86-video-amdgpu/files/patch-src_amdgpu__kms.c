--- src/amdgpu_kms.c.orig	2016-11-17 06:07:48 UTC
+++ src/amdgpu_kms.c
@@ -723,7 +723,7 @@ amdgpu_dirty_update(ScrnInfoPtr scrn)
 {
 	AMDGPUInfoPtr info = AMDGPUPTR(scrn);
 	ScreenPtr screen = scrn->pScreen;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 	RegionPtr region;
 
 	xorg_list_for_each_entry(ent, &screen->pixmap_dirty_list, ent) {

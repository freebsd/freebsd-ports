--- eplaser/gdevescv.c.orig	Sun Aug  1 13:47:00 2004
+++ eplaser/gdevescv.c	Sun Aug  1 14:02:23 2004
@@ -1697,7 +1697,7 @@
 		 gs_logical_operation_t lop, const gx_clip_path * pcpath)
 {
     gx_device_vector const	*vdev = (gx_device_vector *) dev;
-    gx_device_escv const	*pdev = (gx_device_escv *) dev;
+    gx_device_escv 		*pdev = (gx_device_escv *) dev;
     stream			*s = gdev_vector_stream(vdev);
 
     if (w <= 0 || h <= 0) return 0;

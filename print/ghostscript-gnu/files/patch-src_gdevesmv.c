--- eplaser/gdevesmv.c.orig	Sun Aug  1 14:02:52 2004
+++ eplaser/gdevesmv.c	Sun Aug  1 14:03:39 2004
@@ -1797,7 +1797,7 @@
 		 gs_logical_operation_t lop, const gx_clip_path * pcpath)
 {
     gx_device_vector const	*vdev = (gx_device_vector *) dev;
-    gx_device_esmv const	*pdev = (gx_device_esmv *) dev;
+    gx_device_esmv 		*pdev = (gx_device_esmv *) dev;
     stream			*s = gdev_vector_stream(vdev);
     gx_color_index		color = gx_dc_pure_color(pdcolor);
     char			obuf[64];

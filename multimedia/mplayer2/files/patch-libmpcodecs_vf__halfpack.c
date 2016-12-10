--- libmpcodecs/vf_halfpack.c.orig	2013-07-09 16:33:16 UTC
+++ libmpcodecs/vf_halfpack.c
@@ -198,9 +198,9 @@ static int config(struct vf_instance *vf
 		sws_freeContext(vf->priv->ctx);
 		// get unscaled 422p -> yuy2 conversion
 		vf->priv->ctx =
-			sws_getContext(width, height / 2, PIX_FMT_YUV422P,
-			               width, height / 2, PIX_FMT_YUYV422,
-			               SWS_POINT | SWS_PRINT_INFO | get_sws_cpuflags(),
+			sws_getContext(width, height / 2, AV_PIX_FMT_YUV422P,
+			               width, height / 2, AV_PIX_FMT_YUYV422,
+			               SWS_POINT | SWS_PRINT_INFO,
 			               NULL, NULL, NULL);
 	}
 	/* FIXME - also support UYVY output? */

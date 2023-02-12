--- libmpcodecs/ve_lavc.c.orig	2022-08-30 20:40:03 UTC
+++ libmpcodecs/ve_lavc.c
@@ -441,7 +441,7 @@ static int config(struct vf_instance *vf,
 	    mp_msg(MSGT_MENCODER,MSGL_ERR,"error parsing vrc_q\n");
             return 0;
         }
-        lavc_venc_context->rc_override=
+        lavc_venc_context->rc_override=(struct RcOverride *)
             av_reallocp_array(lavc_venc_context->rc_override, i+1, sizeof(*lavc_venc_context->rc_override));
         lavc_venc_context->rc_override[i].start_frame= start;
         lavc_venc_context->rc_override[i].end_frame  = end;

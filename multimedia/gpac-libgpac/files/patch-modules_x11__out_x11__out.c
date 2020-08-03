--- modules/x11_out/x11_out.c.orig	2020-06-16 16:17:17 UTC
+++ modules/x11_out/x11_out.c
@@ -975,10 +975,14 @@ GF_Err X11_ProcessEvent (struct _video_out * vout, GF_
 		case GF_EVENT_SET_GL:
 			if (!xWindow->output_3d) return GF_OK;
 
+#ifdef GPAC_HAS_OPENGL
 			if ( ! glXMakeCurrent(xWindow->display, xWindow->fullscreen ? xWindow->full_wnd : xWindow->wnd, xWindow->glx_context) ) {
 				GF_LOG(GF_LOG_ERROR, GF_LOG_MMIO, ("[X11] Cannot make context current\n"));
 				return GF_IO_ERR;
 			}
+#else
+			return GF_NOT_SUPPORTED;
+#endif
 			break;
 		}
 	} else {

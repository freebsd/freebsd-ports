--- src/bacon-video-widget-xine.c.orig	Sat Apr 17 00:51:30 2004
+++ src/bacon-video-widget-xine.c	Mon Apr 19 19:43:30 2004
@@ -1267,12 +1267,14 @@
 		xine_stop (bvw->priv->stream);
 		message = g_strdup (_("The audio device is busy. Is another application using it?"));
 		break;
+#if 0
 	case XINE_MSG_PERMISSION_ERROR:
 		if (strncmp (bvw->priv->mrl, "file:", 5) == 0)
 			message = g_strdup (_("You are not allowed to open this file."));
 		else
 			message = g_strdup (_("The server refused access to this file or stream."));
 		break;
+#endif
 	}
 
 	if (message == NULL)

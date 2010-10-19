--- src/xmms2.c.orig	2010-09-29 04:54:10.000000000 +0300
+++ src/xmms2.c	2010-09-29 04:55:19.000000000 +0300
@@ -223,7 +223,7 @@
 				break;
 			case XMMS_PLAYBACK_STATUS_STOP:
 				strncpy(ptr->xmms2.status, "Stopped", text_buffer_size - 1);
-				ptr->xmms2.elapsed = ptr->xmms2.progress = ptr->xmms2.percent = 0;
+				ptr->xmms2.elapsed = ptr->xmms2.progress = 0;
 				break;
 			default:
 				strncpy(ptr->xmms2.status, "Unknown", text_buffer_size - 1);

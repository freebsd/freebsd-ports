--- src/mimeview.c.orig	Tue Aug 17 14:17:24 2004
+++ src/mimeview.c	Tue Aug 17 14:24:17 2004
@@ -559,6 +559,7 @@
 		mimeview_launch(mimeview);
 		return;
 	default:
+		break;
 	}
 
 	if (!mimeview->messageview->mainwin) return;

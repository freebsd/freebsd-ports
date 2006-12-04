--- audacious/ui_fileinfo.c.orig	Fri Dec  1 10:30:29 2006
+++ audacious/ui_fileinfo.c	Fri Dec  1 11:14:37 2006
@@ -101,6 +101,7 @@
 	GdkPixbuf *pixbuf;
 	int width, height;
 	double aspect;
+	GdkPixbuf *pixbuf2;
 
 	if (xml == NULL || widget == NULL)
 		return;
@@ -125,7 +126,7 @@
 			height = cfg.filepopup_pixelsize;
 			width = (int)(cfg.filepopup_pixelsize / aspect);
 		}
-		GdkPixbuf *pixbuf2 = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), width, height, GDK_INTERP_BILINEAR);
+		pixbuf2 = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), width, height, GDK_INTERP_BILINEAR);
 		g_object_unref(G_OBJECT(pixbuf));
 		pixbuf = pixbuf2;
 	}
@@ -154,6 +155,7 @@
 	GdkPixbuf *pixbuf;
 	int width, height;
 	double aspect;
+	GdkPixbuf *pixbuf2;
 
 	if (xml == NULL || widget == NULL)
 		return;
@@ -178,7 +180,7 @@
 			height = cfg.filepopup_pixelsize;
 			width = (int)(cfg.filepopup_pixelsize / aspect);
 		}
-		GdkPixbuf *pixbuf2 = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), width, height, GDK_INTERP_BILINEAR);
+		pixbuf2 = gdk_pixbuf_scale_simple(GDK_PIXBUF(pixbuf), width, height, GDK_INTERP_BILINEAR);
 		g_object_unref(G_OBJECT(pixbuf));
 		pixbuf = pixbuf2;
 	}

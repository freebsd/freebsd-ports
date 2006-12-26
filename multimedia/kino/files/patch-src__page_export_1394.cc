--- src/page_export_1394.cc.orig	Sat Dec 23 08:24:23 2006
+++ src/page_export_1394.cc	Mon Dec 25 23:37:13 2006
@@ -63,6 +63,7 @@
 
 void Export1394::start()
 {
+#if 0
 	static raw1394handle_t handle;
 	gchar s[ 512 ];
 
@@ -140,6 +141,7 @@
 	{
 		gtk_widget_set_sensitive ( GTK_WIDGET ( tmp ), FALSE );
 	}
+#endif
 }
 
 /** Define active widgets.

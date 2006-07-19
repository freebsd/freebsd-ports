--- src/page_export_1394.cc.orig	Sun May 21 23:03:27 2006
+++ src/page_export_1394.cc	Tue Jul 18 22:59:27 2006
@@ -63,6 +63,7 @@
 
 void Export1394::start()
 {
+#if 0
 	static raw1394handle_t handle;
 	gchar s[ 512 ];
 
@@ -140,6 +141,7 @@
 				   );
 #endif
 
+#endif
 }
 
 /** Define active widgets.

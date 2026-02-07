--- clients/lcdproc/iface.h.orig	2020-09-28 23:24:28.536083000 +0200
+++ clients/lcdproc/iface.h	2020-09-28 23:24:52.494772000 +0200
@@ -18,7 +18,7 @@
 /** max number of interfaces in multi-interface mode */
 #define MAX_INTERFACES 3
 
-IfaceInfo iface[MAX_INTERFACES];	/* interface info */
+extern IfaceInfo iface[MAX_INTERFACES];	/* interface info */
 
 /** Update screen content */
 int iface_screen(int rep, int display, int *flags_ptr);

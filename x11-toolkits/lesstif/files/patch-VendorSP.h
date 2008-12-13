--- include/Motif-2.1/Xm/VendorSP.h.BAD	2006-08-30 11:00:30.000000000 -0500
+++ include/Motif-2.1/Xm/VendorSP.h	2006-08-30 11:00:47.000000000 -0500
@@ -28,12 +28,13 @@
 
 #include <Xm/XmP.h>
 #include <Xm/VendorS.h>
-#include <X11/ShellP.h>
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
+#include <X11/ShellP.h>
+
 XMLIBEXPORT extern Cardinal _XmFilterResources(XtResource *resources,
 				   Cardinal numResources,
 				   WidgetClass filterClass,

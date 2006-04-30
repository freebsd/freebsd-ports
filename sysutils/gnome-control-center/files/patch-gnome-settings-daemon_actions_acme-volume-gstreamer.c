--- gnome-settings-daemon/actions/acme-volume-gstreamer.c.orig	Mon Apr 17 22:23:18 2006
+++ gnome-settings-daemon/actions/acme-volume-gstreamer.c	Mon Apr 17 22:25:17 2006
@@ -29,6 +29,7 @@
 
 #ifdef HAVE_GST10
 #include <gst/gst.h>
+#include <gst/audio/mixerutils.h>
 #include <gst/interfaces/mixer.h>
 #include <gst/interfaces/propertyprobe.h>
 #else

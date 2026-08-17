--- tools/legacy/sample_common/src/gtkutils.cpp.orig	2026-06-25 23:06:43 UTC
+++ tools/legacy/sample_common/src/gtkutils.cpp
@@ -5,7 +5,7 @@
   ############################################################################*/
 #if defined(LIBVA_GTK4_SUPPORT)
     #include "gtkutils.h"
-    #include <drm/drm_fourcc.h>
+    #include <libdrm/drm_fourcc.h>
     #include <gdk/wayland/gdkwayland.h>
     #include <gdk/x11/gdkx.h>
     #include <gtk/gtk.h>

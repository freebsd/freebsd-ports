--- layout/svg/renderer/src/cairo/nsSVGCairoCanvas.cpp.orig	Thu Mar 10 12:22:22 2005
+++ layout/svg/renderer/src/cairo/nsSVGCairoCanvas.cpp	Thu Mar 10 12:22:59 2005
@@ -50,6 +50,7 @@
 #include "nsRenderingContextGTK.h"
 #include <gdk/gdkx.h>
 #include <cairo.h>
+#include <cairo-xlib.h>
 
 /**
  * \addtogroup cairo_renderer Cairo Rendering Engine

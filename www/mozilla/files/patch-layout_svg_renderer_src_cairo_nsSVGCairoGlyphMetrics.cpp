--- layout/svg/renderer/src/cairo/nsSVGCairoGlyphMetrics.cpp.orig	Thu Mar 10 12:24:44 2005
+++ layout/svg/renderer/src/cairo/nsSVGCairoGlyphMetrics.cpp	Thu Mar 10 12:25:25 2005
@@ -51,6 +51,7 @@
 #include "nsSVGTypeCIDs.h"
 #include "nsIComponentManager.h"
 #include <cairo.h>
+#include <stdlib.h>
 
 /**
  * \addtogroup gdiplus_renderer Cairo Rendering Engine

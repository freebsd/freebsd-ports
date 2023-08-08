Index: Source/WebCore/rendering/RenderLayerBacking.h
--- Source/WebCore/rendering/RenderLayerBacking.h.orig
+++ Source/WebCore/rendering/RenderLayerBacking.h
@@ -33,6 +33,12 @@
 #include "RenderLayerCompositor.h"
 #include "ScrollingCoordinator.h"
 
+#if defined(_LP64)
+#  define __WORDSIZE 64
+#else
+#  define __WORDSIZE 32
+#endif
+
 namespace WebCore {
 
 class EventRegionContext;

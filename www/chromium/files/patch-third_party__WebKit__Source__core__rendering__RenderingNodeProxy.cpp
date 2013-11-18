--- third_party/WebKit/Source/core/rendering/RenderingNodeProxy.cpp.orig	2013-11-16 01:26:13.000000000 +0100
+++ third_party/WebKit/Source/core/rendering/RenderingNodeProxy.cpp	2013-11-18 00:00:41.000000000 +0100
@@ -31,6 +31,7 @@
 #include "config.h"
 #include "core/rendering/RenderingNodeProxy.h"
 
+#include "core/dom/Element.h"
 #include "core/dom/Node.h"
 
 namespace WebCore {

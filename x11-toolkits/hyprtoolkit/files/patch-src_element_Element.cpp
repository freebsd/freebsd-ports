--- src/element/Element.cpp.orig	2025-11-12 08:13:02 UTC
+++ src/element/Element.cpp
@@ -7,6 +7,8 @@
 #include "../window/ToolkitWindow.hpp"
 #include "../layout/Positioner.hpp"
 
+#include <algorithm>
+
 using namespace Hyprtoolkit;
 using namespace Hyprutils::Math;
 

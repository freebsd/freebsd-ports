--- third_party/blink/renderer/core/dom/tree_scope.h.orig	2026-08-31 10:59:09 UTC
+++ third_party/blink/renderer/core/dom/tree_scope.h
@@ -28,6 +28,7 @@
 #define THIRD_PARTY_BLINK_RENDERER_CORE_DOM_TREE_SCOPE_H_
 
 #include "third_party/blink/renderer/core/core_export.h"
+#include "third_party/blink/renderer/core/css/css_style_sheet.h"
 #include "third_party/blink/renderer/core/dom/tree_ordered_map.h"
 #include "third_party/blink/renderer/core/html/custom/custom_element_registry_assignment.h"
 #include "third_party/blink/renderer/core/html/forms/radio_button_group_scope.h"

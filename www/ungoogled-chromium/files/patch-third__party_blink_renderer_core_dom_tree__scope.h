--- third_party/blink/renderer/core/dom/tree_scope.h.orig	2025-11-01 06:40:37 UTC
+++ third_party/blink/renderer/core/dom/tree_scope.h
@@ -28,6 +28,7 @@
 #define THIRD_PARTY_BLINK_RENDERER_CORE_DOM_TREE_SCOPE_H_
 
 #include "third_party/blink/renderer/core/core_export.h"
+#include "third_party/blink/renderer/core/css/css_style_sheet.h"
 #include "third_party/blink/renderer/core/dom/tree_ordered_map.h"
 #include "third_party/blink/renderer/core/html/forms/radio_button_group_scope.h"
 #include "third_party/blink/renderer/core/layout/hit_test_request.h"

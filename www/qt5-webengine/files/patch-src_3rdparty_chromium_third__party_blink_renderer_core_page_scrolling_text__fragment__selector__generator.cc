--- src/3rdparty/chromium/third_party/blink/renderer/core/page/scrolling/text_fragment_selector_generator.cc.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/page/scrolling/text_fragment_selector_generator.cc
@@ -6,6 +6,7 @@
 
 #include "base/metrics/histogram_macros.h"
 #include "base/time/default_tick_clock.h"
+#include "third_party/abseil-cpp/absl/base/macros.h"
 #include "third_party/blink/public/common/browser_interface_broker_proxy.h"
 #include "third_party/blink/public/platform/interface_registry.h"
 #include "third_party/blink/renderer/core/editing/ephemeral_range.h"

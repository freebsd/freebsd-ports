--- content/browser/font_access/font_enumeration_cache.h.orig	2022-02-07 13:39:41 UTC
+++ content/browser/font_access/font_enumeration_cache.h
@@ -24,7 +24,7 @@
 #include "third_party/blink/public/mojom/font_access/font_access.mojom.h"
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #define PLATFORM_HAS_LOCAL_FONT_ENUMERATION_IMPL 1
 #endif
 

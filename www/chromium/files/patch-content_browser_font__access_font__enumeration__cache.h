--- content/browser/font_access/font_enumeration_cache.h.orig	2021-09-24 04:26:05 UTC
+++ content/browser/font_access/font_enumeration_cache.h
@@ -22,7 +22,7 @@
 #include "third_party/blink/public/common/font_access/font_enumeration_table.pb.h"
 #include "third_party/blink/public/mojom/font_access/font_access.mojom.h"
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 #define PLATFORM_HAS_LOCAL_FONT_ENUMERATION_IMPL 1
 #endif

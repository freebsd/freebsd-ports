--- content/browser/font_access/font_enumeration_cache.h.orig	2022-02-28 16:54:41 UTC
+++ content/browser/font_access/font_enumeration_cache.h
@@ -24,7 +24,7 @@
 #include "third_party/blink/public/mojom/font_access/font_access.mojom.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #define PLATFORM_HAS_LOCAL_FONT_ENUMERATION_IMPL 1
 #endif
 

--- chrome/browser/intranet_redirect_detector.h.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -26,7 +26,7 @@ class SimpleURLLoader;
 class PrefRegistrySimple;
 
 #if !(BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-      BUILDFLAG(IS_CHROMEOS))
+      BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif
 

--- chrome/browser/intranet_redirect_detector.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -25,7 +25,7 @@ class SimpleURLLoader;
 class PrefRegistrySimple;
 
 #if !(BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-      BUILDFLAG(IS_CHROMEOS))
+      BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif
 

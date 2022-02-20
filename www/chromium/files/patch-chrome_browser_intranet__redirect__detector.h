--- chrome/browser/intranet_redirect_detector.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -27,7 +27,7 @@ class SimpleURLLoader;
 class PrefRegistrySimple;
 
 #if !(defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-      defined(OS_CHROMEOS) || defined(OS_FUCHSIA))
+      defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif
 

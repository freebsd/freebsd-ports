--- chrome/browser/intranet_redirect_detector.h.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -27,7 +27,7 @@ class SimpleURLLoader;
 
 class PrefRegistrySimple;
 
-#if !(defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if !(defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
       defined(OS_CHROMEOS) || defined(OS_FUCHSIA))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif

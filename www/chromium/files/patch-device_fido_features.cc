--- device/fido/features.cc.orig	2025-12-05 10:12:50 UTC
+++ device/fido/features.cc
@@ -37,7 +37,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockErrorUi, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif

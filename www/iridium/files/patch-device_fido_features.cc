--- device/fido/features.cc.orig	2026-01-16 14:21:21 UTC
+++ device/fido/features.cc
@@ -37,7 +37,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockManager, base::FEATURE_DISABLED_BY_DEFAULT);
 

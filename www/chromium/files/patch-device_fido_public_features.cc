--- device/fido/public/features.cc.orig	2026-02-11 09:05:39 UTC
+++ device/fido/public/features.cc
@@ -40,7 +40,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockManager, base::FEATURE_DISABLED_BY_DEFAULT);
 

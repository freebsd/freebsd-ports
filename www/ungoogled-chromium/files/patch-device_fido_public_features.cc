--- device/fido/public/features.cc.orig	2026-10-31 12:09:36 UTC
+++ device/fido/public/features.cc
@@ -34,7 +34,7 @@ namespace device {
 // comment.
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Not yet enabled by default.
 BASE_FEATURE(kPasskeyUnlockErrorUi, base::FEATURE_DISABLED_BY_DEFAULT);
 

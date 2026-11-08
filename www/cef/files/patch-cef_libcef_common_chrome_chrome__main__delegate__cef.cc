--- cef/libcef/common/chrome/chrome_main_delegate_cef.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/common/chrome/chrome_main_delegate_cef.cc
@@ -147,7 +147,7 @@ ChromeMainDelegateCef::ChromeMainDelegat
       runner_(runner),
       settings_(settings),
       application_(application) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   resource_util::OverrideAssetPath();
 #endif
 }

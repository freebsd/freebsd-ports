--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2025-03-09 21:38:10 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -28,7 +28,7 @@ bool IsOsSupportedForCart() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2024-09-30 07:45:04 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -24,7 +24,7 @@ bool IsOsSupportedForCart() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

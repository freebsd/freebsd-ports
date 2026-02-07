--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2026-01-16 13:40:34 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -41,7 +41,7 @@ bool IsOsSupportedForCart() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

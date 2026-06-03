--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2026-04-15 11:25:12 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -55,7 +55,7 @@ bool IsOsSupportedForCart() {
 }
 
 bool IsOsSupportedForDrive() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

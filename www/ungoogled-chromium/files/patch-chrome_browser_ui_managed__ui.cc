--- chrome/browser/ui/managed_ui.cc.orig	2023-07-21 09:49:17 UTC
+++ chrome/browser/ui/managed_ui.cc
@@ -92,7 +92,7 @@ bool ShouldDisplayManagedByParentUi(Profile* profile) 
   return false;
 #else
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // The EnableManagedByParentUiOnDesktop flag depends on
   // EnableSupervisionOnDesktopAndIOS.
   CHECK(

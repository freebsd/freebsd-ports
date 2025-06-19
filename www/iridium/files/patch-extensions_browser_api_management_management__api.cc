--- extensions/browser/api/management/management_api.cc.orig	2025-06-19 07:37:57 UTC
+++ extensions/browser/api/management/management_api.cc
@@ -284,7 +284,7 @@ void AddExtensionInfo(const Extension* source_extensio
 
 bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

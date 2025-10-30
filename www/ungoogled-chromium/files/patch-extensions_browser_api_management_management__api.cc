--- extensions/browser/api/management/management_api.cc.orig	2025-11-01 06:40:37 UTC
+++ extensions/browser/api/management/management_api.cc
@@ -296,7 +296,7 @@ void AddExtensionInfo(const Extension* source_extensio
 
 bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

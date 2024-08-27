--- chrome/browser/extensions/api/webstore_private/webstore_private_api.cc.orig	2024-08-27 06:28:16 UTC
+++ chrome/browser/extensions/api/webstore_private/webstore_private_api.cc
@@ -910,7 +910,7 @@ void WebstorePrivateBeginInstallWithManifest3Function:
 #if BUILDFLAG(IS_CHROMEOS)
       RequestExtensionApproval(contents);
       return;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // Shows a parental permission dialog directly bypassing the extension
       // install dialog view. The parental permission dialog contains a superset
       // of data from the extension install dialog: requested extension

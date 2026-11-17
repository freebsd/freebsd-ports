--- src/extensions/browser/api/webstore_private/webstore_private_api.cc.orig	2026-10-18 18:43:23 UTC
+++ src/extensions/browser/api/webstore_private/webstore_private_api.cc
@@ -1190,7 +1190,7 @@ void WebstorePrivateBeginInstallWithMani
 #if BUILDFLAG(IS_CHROMEOS)
       RequestExtensionApproval(contents);
       return;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // Shows a parental permission dialog directly bypassing the extension
       // install dialog view. The parental permission dialog contains a superset
       // of data from the extension install dialog: requested extension

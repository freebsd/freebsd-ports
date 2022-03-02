--- chrome/browser/web_applications/web_app_file_handler_registration.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/web_applications/web_app_file_handler_registration.h
@@ -44,7 +44,7 @@ void UnregisterFileHandlersWithOs(const AppId& app_id,
                                   Profile* profile,
                                   ResultCallback callback);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Exposed for testing purposes. Register the set of
 // MIME-type-to-file-extensions mappings corresponding to |file_handlers|. File
 // I/O and a a callout to the Linux shell are performed asynchronously.

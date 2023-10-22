--- chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/web_applications/os_integration/web_app_file_handler_registration.h
@@ -44,7 +44,7 @@ void UnregisterFileHandlersWithOs(const webapps::AppId
                                   const base::FilePath& profile_path,
                                   ResultCallback callback);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Exposed for testing purposes. Register the set of
 // MIME-type-to-file-extensions mappings corresponding to |file_handlers|. File
 // I/O and callouts to the Linux shell are performed asynchronously.

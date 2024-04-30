--- src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.h.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.h
@@ -184,7 +184,7 @@ class ContentBrowserClientImpl : public content::Conte
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,

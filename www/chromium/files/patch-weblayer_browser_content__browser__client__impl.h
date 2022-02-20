--- weblayer/browser/content_browser_client_impl.h.orig	2022-02-07 13:39:41 UTC
+++ weblayer/browser/content_browser_client_impl.h
@@ -178,7 +178,7 @@ class ContentBrowserClientImpl : public content::Conte
       override;
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_ANDROID) || defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,

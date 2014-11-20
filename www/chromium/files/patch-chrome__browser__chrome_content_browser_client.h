--- chrome/browser/chrome_content_browser_client.h.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -278,7 +278,7 @@
   virtual net::CookieStore* OverrideCookieStoreForRenderProcess(
       int render_process_id) OVERRIDE;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,

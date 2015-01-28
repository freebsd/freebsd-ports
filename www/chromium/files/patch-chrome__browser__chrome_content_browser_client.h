--- chrome/browser/chrome_content_browser_client.h.orig	2015-01-21 20:28:15 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -262,7 +262,7 @@
   net::CookieStore* OverrideCookieStoreForRenderProcess(
       int render_process_id) override;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,

--- src/3rdparty/chromium/content/browser/webui/web_ui_main_frame_observer.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/browser/webui/web_ui_main_frame_observer.h
@@ -45,7 +45,7 @@ class CONTENT_EXPORT WebUIMainFrameObserver : public W
 
 // TODO(crbug.com/1129544) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On official Google builds, capture and report JavaScript error messages on
   // WebUI surfaces back to Google. This allows us to fix JavaScript errors and
   // exceptions.
@@ -61,7 +61,7 @@ class CONTENT_EXPORT WebUIMainFrameObserver : public W
   void ReadyToCommitNavigation(NavigationHandle* navigation_handle) override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void MaybeEnableWebUIJavaScriptErrorReporting(
       NavigationHandle* navigation_handle);
 

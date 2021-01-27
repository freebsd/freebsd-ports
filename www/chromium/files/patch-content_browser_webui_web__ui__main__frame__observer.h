--- content/browser/webui/web_ui_main_frame_observer.h.orig	2021-01-19 11:37:39 UTC
+++ content/browser/webui/web_ui_main_frame_observer.h
@@ -40,7 +40,7 @@ class CONTENT_EXPORT WebUIMainFrameObserver : public W
 
 // TODO(crbug.com/1129544) This is currently disabled due to Windows DLL
 // thunking issues. Fix & re-enable.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On official Google builds, capture and report JavaScript error messages on
   // WebUI surfaces back to Google. This allows us to fix JavaScript errors and
   // exceptions.
@@ -49,7 +49,7 @@ class CONTENT_EXPORT WebUIMainFrameObserver : public W
                                 const base::string16& message,
                                 int32_t line_no,
                                 const base::string16& source_id) override;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
  private:
   WebUIImpl* web_ui_;

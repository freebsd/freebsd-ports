--- chrome/browser/ui/webui/settings/accessibility_main_handler.h.orig	2024-03-22 14:16:19 UTC
+++ chrome/browser/ui/webui/settings/accessibility_main_handler.h
@@ -37,7 +37,7 @@ class AccessibilityMainHandler
   void HandleGetScreenReaderState(const base::Value::List& args);
   void HandleCheckAccessibilityImageLabels(const base::Value::List& args);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void HandleGetScreenAIInstallState(const base::Value::List& args);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 

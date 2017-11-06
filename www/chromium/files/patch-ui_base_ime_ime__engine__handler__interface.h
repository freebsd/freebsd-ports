--- ui/base/ime/ime_engine_handler_interface.h.orig	2017-06-05 19:03:30 UTC
+++ ui/base/ime/ime_engine_handler_interface.h
@@ -142,7 +142,7 @@ class UI_BASE_IME_EXPORT IMEEngineHandlerInterface {
   // Hides the input view window (from API call).
   virtual void HideInputView() = 0;
 
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
   // Get the id of the IME extension.
   virtual std::string GetExtensionId() const = 0;

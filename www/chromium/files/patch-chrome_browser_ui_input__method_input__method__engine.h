--- chrome/browser/ui/input_method/input_method_engine.h.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/input_method/input_method_engine.h
@@ -27,7 +27,7 @@ class InputMethodEngine : public InputMe
 
   // ui::IMEEngineHandlerInterface:
   bool IsActive() const override;
-  std::string GetExtensionId() const override;
+  std::string GetExtensionId() const;
 
   // Creates and shows the IME window.
   // Returns 0 for errors and |error| will contains the error message.

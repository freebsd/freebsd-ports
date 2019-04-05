--- ui/base/ime/ime_engine_handler_interface.h.orig	2019-03-11 22:01:19 UTC
+++ ui/base/ime/ime_engine_handler_interface.h
@@ -166,7 +166,7 @@ class UI_BASE_IME_EXPORT IMEEngineHandlerInterface {
   virtual void SetMirroringEnabled(bool mirroring_enabled) = 0;
   virtual void SetCastingEnabled(bool casting_enabled) = 0;
 
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
   // Get the id of the IME extension.
   virtual std::string GetExtensionId() const = 0;

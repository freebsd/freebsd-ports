--- native/context.cpp.orig	2026-09-08 14:07:06 UTC
+++ native/context.cpp
@@ -196,7 +196,7 @@ bool Context::Initialize(JNIEnv* env,
   //   renderer process.
   settings.no_sandbox = true;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)
   // Use external message pump with OSR.
   external_message_pump_ = !!settings.windowless_rendering_enabled;
   if (!external_message_pump_) {

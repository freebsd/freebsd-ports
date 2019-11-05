--- device/gamepad/gamepad_provider.cc.orig	2019-10-21 19:06:34 UTC
+++ device/gamepad/gamepad_provider.cc
@@ -167,7 +167,7 @@ void GamepadProvider::Initialize(std::unique_ptr<Gamep
 
   if (!polling_thread_)
     polling_thread_.reset(new base::Thread("Gamepad polling thread"));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;

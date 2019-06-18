--- device/gamepad/gamepad_provider.cc.orig	2019-03-11 22:00:58 UTC
+++ device/gamepad/gamepad_provider.cc
@@ -164,7 +164,7 @@ void GamepadProvider::Initialize(std::unique_ptr<Gamep
     monitor->AddDevicesChangedObserver(this);
 
   polling_thread_.reset(new base::Thread("Gamepad polling thread"));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessageLoop::Type kMessageLoopType = base::MessageLoop::TYPE_IO;

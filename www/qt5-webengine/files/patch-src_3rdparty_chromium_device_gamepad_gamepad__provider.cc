--- src/3rdparty/chromium/device/gamepad/gamepad_provider.cc.orig	2017-02-02 02:02:54 UTC
+++ src/3rdparty/chromium/device/gamepad/gamepad_provider.cc
@@ -145,7 +145,7 @@ void GamepadProvider::Initialize(std::un
     monitor->AddDevicesChangedObserver(this);
 
   polling_thread_.reset(new base::Thread("Gamepad polling thread"));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessageLoop::Type kMessageLoopType = base::MessageLoop::TYPE_IO;

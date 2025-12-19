--- src/3rdparty/chromium/device/gamepad/gamepad_provider.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/device/gamepad/gamepad_provider.cc
@@ -159,7 +159,7 @@ void GamepadProvider::Initialize(std::unique_ptr<Gamep
 
   if (!polling_thread_)
     polling_thread_ = std::make_unique<base::Thread>("Gamepad polling thread");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, the data fetcher needs to watch file descriptors, so the message
   // loop needs to be a libevent loop.
   const base::MessagePumpType kMessageLoopType = base::MessagePumpType::IO;

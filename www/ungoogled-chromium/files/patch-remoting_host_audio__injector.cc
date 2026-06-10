--- remoting/host/audio_injector.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/host/audio_injector.cc
@@ -8,7 +8,7 @@
 #include "build/build_config.h"
 #include "remoting/proto/audio.pb.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/pipewire_audio_injector.h"
 #endif
 
@@ -26,7 +26,7 @@ void AudioInjector::ProcessAudioPacket(std::unique_ptr
 
 // static
 bool AudioInjector::IsSupported() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, we check if PipeWire is available and can be initialized.
   // Note that in multi-process mode, this may return true in the network
   // process because the libraries are loadable, even though the virtual audio

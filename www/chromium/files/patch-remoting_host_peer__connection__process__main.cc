--- remoting/host/peer_connection_process_main.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/peer_connection_process_main.cc
@@ -26,7 +26,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <memory>
 
 #include "base/logging.h"
@@ -83,7 +83,7 @@ int PeerConnectionProcessMain() {
     return kInitializationFailed;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Engage the multi-threaded Seccomp-BPF sandbox after establishing the
   // initial Mojo IPC connection with the parent process, but before starting
   // the main RunLoop to process untrusted WebRTC peer traffic and remote

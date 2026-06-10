--- remoting/host/setup/daemon_controller.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/host/setup/daemon_controller.cc
@@ -63,7 +63,7 @@ bool DaemonController::is_privileged() const {
   return delegate_->is_privileged();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool DaemonController::is_multi_process() const {
   return delegate_->is_multi_process();
 }

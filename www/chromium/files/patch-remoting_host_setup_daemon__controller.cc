--- remoting/host/setup/daemon_controller.cc.orig	2026-10-18 13:29:39 UTC
+++ remoting/host/setup/daemon_controller.cc
@@ -53,7 +53,7 @@ bool DaemonController::is_privileged() const {
   return delegate_->is_privileged();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool DaemonController::is_multi_process() const {
   return delegate_->is_multi_process();
 }

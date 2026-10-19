--- remoting/host/setup/daemon_controller.h.orig	2026-10-18 13:29:39 UTC
+++ remoting/host/setup/daemon_controller.h
@@ -156,13 +156,13 @@ class DaemonController : public base::RefCountedThread
     // unprivileged.
     virtual bool is_privileged() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Returns true if the host has a multi-process architecture.
     virtual bool is_multi_process() const = 0;
 #endif
   };
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the host type. If nullptr is passed (the default), the host type will
   // be automatically determined by checking which host type is running. If none
   // is running, HostType::GetDefaultHostType() will be used.
@@ -231,7 +231,7 @@ class DaemonController : public base::RefCountedThread
   // unprivileged.
   bool is_privileged() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns true if the host has a multi-process architecture.
   bool is_multi_process() const;
 #endif

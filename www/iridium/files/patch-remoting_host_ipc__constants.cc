--- remoting/host/ipc_constants.cc.orig	2022-12-01 10:35:46 UTC
+++ remoting/host/ipc_constants.cc
@@ -17,7 +17,7 @@ namespace remoting {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if !defined(NDEBUG)
 // Use a different IPC name for debug builds so that we can run the host
@@ -65,7 +65,7 @@ const mojo::NamedPlatformChannel::ServerName&
 GetChromotingHostServicesServerName() {
   static const base::NoDestructor<mojo::NamedPlatformChannel::ServerName>
       server_name(WorkingDirectoryIndependentServerNameFromUTF8(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           // Linux host creates the socket file in /tmp, and it won't be deleted
           // until reboot, so we put username in the path in case the user
           // switches the host owner.

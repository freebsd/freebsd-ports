--- remoting/host/chromoting_host_services_server.cc.orig	2026-07-01 06:24:19 UTC
+++ remoting/host/chromoting_host_services_server.cc
@@ -16,7 +16,7 @@
 #include "remoting/host/mojo_caller_security_checker.h"
 #include "remoting/host/mojom/chromoting_host_services.mojom.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <unistd.h>
 #endif
 
@@ -47,7 +47,7 @@ named_mojo_ipc_server::EndpointOptions CreateEndpointO
   options.include_peer_process_info = true;
   options.extra_send_invitation_flags =
       MOJO_SEND_INVITATION_FLAG_UNTRUSTED_PROCESS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Allow the endpoint to be connected by any users iff the server is run as
   // root.
   options.require_same_peer_user = (getuid() != 0);
@@ -60,7 +60,7 @@ named_mojo_ipc_server::EndpointOptions CreateEndpointO
 ChromotingHostServicesServer::ChromotingHostServicesServer(
     BindChromotingHostServicesCallback bind_chromoting_host_services)
     : ChromotingHostServicesServer(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           // For the multi-process host, the server is run as root; for the
           // legacy single-process host, the server is run as the login user.
           (getuid() == 0) ? GetChromotingHostServicesServerName()

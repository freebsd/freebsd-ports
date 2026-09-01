--- remoting/host/chromoting_host.h.orig	2026-08-31 10:59:09 UTC
+++ remoting/host/chromoting_host.h
@@ -37,7 +37,7 @@
 #include "remoting/protocol/session_manager.h"
 #include "remoting/protocol/transport_context.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/chromoting_host_services_server.h"
 #endif
 
@@ -73,7 +73,7 @@ class ChromotingHost :
 // multi-process host, ChromotingHostServices is implemented by the daemon
 // process and the ChromotingSessionServices receiver is passed through
 // DesktopSessionConnectionEvents.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     public mojom::ChromotingHostServices,
 
 #endif
@@ -118,7 +118,7 @@ class ChromotingHost :
   // This method can only be called once during the lifetime of this object.
   void Start(const std::string& host_owner);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Starts running the ChromotingHostServices server and listening for incoming
   // IPC binding requests.
   // Currently only the single-process Linux host runs the
@@ -130,7 +130,7 @@ class ChromotingHost :
       std::unique_ptr<named_mojo_ipc_server::ConnectionInfo> connection_info);
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void BindChromotingHostServices(
       mojo::PendingReceiver<mojom::ChromotingHostServices> receiver);
 #endif
@@ -165,7 +165,7 @@ class ChromotingHost :
   std::optional<ErrorCode> OnSessionPoliciesReceived(
       const SessionPolicies& policies) override;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // mojom::ChromotingHostServices implementation.
   void BindSessionServices(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver)
@@ -223,7 +223,7 @@ class ChromotingHost :
   // List of host extensions.
   std::vector<std::unique_ptr<HostExtension>> extensions_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // IPC server that runs the CRD host service API. Non-null if the server name
   // is set and the host is started.
   // Currently only Linux runs the ChromotingHostServices server on the host
@@ -231,7 +231,7 @@ class ChromotingHost :
   std::unique_ptr<ChromotingHostServicesServer> ipc_server_;
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   mojo::ReceiverSet<mojom::ChromotingHostServices> receivers_;
 #endif
 

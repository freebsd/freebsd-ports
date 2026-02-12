--- components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc.orig	2026-02-12 08:43:57 UTC
+++ components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc
@@ -7,6 +7,10 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/un.h>
+#endif
+
 #include <memory>
 #include <utility>
 
@@ -84,12 +88,20 @@ void NamedMojoServerEndpointConnectorLinux::OnSocketRe
 
   auto info = std::make_unique<ConnectionInfo>();
   socklen_t len = sizeof(info->credentials);
+#if BUILDFLAG(IS_FREEBSD)
+  if (getsockopt(connection_fd.get(), SOL_SOCKET, LOCAL_PEERCRED,
+#else
   if (getsockopt(connection_fd.get(), SOL_SOCKET, SO_PEERCRED,
+#endif
                  &info->credentials, &len) != 0) {
     PLOG(ERROR) << "getsockopt failed.";
     return;
   }
+#if BUILDFLAG(IS_FREEBSD)
+  info->pid = info->credentials.cr_pid;
+#elif !BUILDFLAG(IS_OPENBSD)
   info->pid = info->credentials.pid;
+#endif
 
   mojo::PlatformChannelEndpoint endpoint(
       mojo::PlatformHandle(std::move(connection_fd)));

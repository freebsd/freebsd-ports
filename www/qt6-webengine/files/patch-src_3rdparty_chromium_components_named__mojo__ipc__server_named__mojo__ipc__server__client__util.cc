--- src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc
@@ -23,7 +23,7 @@ mojo::PlatformChannelEndpoint ConnectToServer(
 // static
 mojo::PlatformChannelEndpoint ConnectToServer(
     const mojo::NamedPlatformChannel::ServerName& server_name) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return mojo::NamedPlatformChannel::ConnectToServer(server_name);
 #elif BUILDFLAG(IS_MAC)
   mojo::PlatformChannelEndpoint endpoint =

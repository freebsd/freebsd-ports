--- src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc
@@ -23,7 +23,7 @@ mojo::PlatformChannelEndpoint ConnectToServer(
 // static
 mojo::PlatformChannelEndpoint ConnectToServer(
     const mojo::NamedPlatformChannel::Options& options) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return mojo::NamedPlatformChannel::ConnectToServer(options);
 #elif BUILDFLAG(IS_MAC)
   mojo::PlatformChannelEndpoint endpoint =

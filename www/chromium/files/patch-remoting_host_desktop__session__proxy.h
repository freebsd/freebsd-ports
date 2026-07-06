--- remoting/host/desktop_session_proxy.h.orig	2026-07-01 06:24:19 UTC
+++ remoting/host/desktop_session_proxy.h
@@ -108,7 +108,7 @@ class DesktopSessionProxy
   std::unique_ptr<UrlForwarderConfigurator> CreateUrlForwarderConfigurator();
   std::unique_ptr<RemoteWebAuthnStateChangeNotifier>
   CreateRemoteWebAuthnStateChangeNotifier();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnSessionServicesClientConnected(
       mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver);
 #endif

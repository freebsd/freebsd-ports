--- src/remoting/host/desktop_session_proxy.cc.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/host/desktop_session_proxy.cc
@@ -168,7 +168,7 @@ DesktopSessionProxy::CreateRemoteWebAuth
       base::BindRepeating(&DesktopSessionProxy::SignalWebAuthnExtension, this));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopSessionProxy::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -208,7 +208,7 @@ std::string DesktopSessionProxy::GetCapa
     result += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   result += " ";
   result += protocol::kClientControlledLayoutCapability;
 #endif

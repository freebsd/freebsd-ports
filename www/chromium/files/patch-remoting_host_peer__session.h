--- remoting/host/peer_session.h.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/peer_session.h
@@ -19,7 +19,7 @@
 #include "remoting/proto/control.pb.h"
 #include "remoting/protocol/errors.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/mojom/peer_session.mojom.h"
 #endif
 
@@ -40,7 +40,7 @@ struct SessionPolicies;
 class PeerSession {
  public:
   // LINT.IfChange(peer_session_event_handler)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Windows and Linux, `PeerSession::EventHandler` is an alias to the
   // generated Mojo interface `mojom::PeerSessionEventHandler`.
   using EventHandler = mojom::PeerSessionEventHandler;

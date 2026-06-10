--- remoting/protocol/webrtc_transport.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/protocol/webrtc_transport.cc
@@ -1202,7 +1202,7 @@ void WebrtcTransport::SendOffer() {
   // `recvonly` if microphone remoting is not enabled. Only Linux hosts support
   // audio injection (microphone remoting).
   // TODO: crbug.com/513327818 - Hook this up with AudioInjector::IsSupported().
-  options.offer_to_receive_audio = BUILDFLAG(IS_LINUX);
+  options.offer_to_receive_audio = BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD);
   options.ice_restart = want_ice_restart_;
   peer_connection()->CreateOffer(
       CreateSessionDescriptionObserver::Create(

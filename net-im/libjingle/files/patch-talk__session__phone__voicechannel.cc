--- talk/session/phone/voicechannel.cc.orig	Fri Mar  3 08:39:15 2006
+++ talk/session/phone/voicechannel.cc	Fri Mar  3 08:39:36 2006
@@ -159,7 +159,7 @@
   channel_->OnPacketReceived(data, (int)len);
 }
 
-void VoiceChannel::SendPacket(const void *data, unsigned int len) {
+void VoiceChannel::SendPacket(const void *data, size_t len) {
   // SendPacket gets called from MediaEngine; send to socket
   // MediaEngine will call us on a random thread.  The Send operation on the socket is
   // special in that it can handle this.

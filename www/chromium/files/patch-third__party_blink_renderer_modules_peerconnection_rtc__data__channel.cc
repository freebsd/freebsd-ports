--- third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc.orig	2026-06-04 10:12:25 UTC
+++ third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc
@@ -567,6 +567,7 @@ void RTCDataChannel::send(Blob* data, ExceptionState& 
   pending_messages_.push_back(message);
 }
 
+#undef close
 void RTCDataChannel::close() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   if (state_ == webrtc::DataChannelInterface::kClosing ||

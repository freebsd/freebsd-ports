--- player/src/mpeg3_rtp_bytestream.cpp.orig	Thu Sep 30 03:10:31 2004
+++ player/src/mpeg3_rtp_bytestream.cpp	Thu Sep 30 03:09:12 2004
@@ -32,6 +32,10 @@
 #else
 #define rtp_message(loglevel, fmt...) message(loglevel, "rtpbyst", fmt)
 #endif
+
+uint8_t temp_ref;
+int frame_type;
+
 static rtp_packet *end_of_pak (rtp_packet *start)
 {
   while (start->rtp_next->rtp_pak_ts == start->rtp_pak_ts) 
@@ -74,7 +78,6 @@
   int32_t diff;
   int correct_hdr;
   int dropped_seq;
-  uint8_t temp_ref;
   diff = m_buffer_len - m_bytes_used;
 
   if (diff > 2) {
@@ -86,7 +89,6 @@
 #endif
     return (m_last_realtime);
   }
-  int frame_type;
   m_buffer_len = 0;
   dropped_seq = 0;
   while (finished == 0) {

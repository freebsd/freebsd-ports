--- libicq2000-0.1/src/DirectClient.cpp.orig	Wed Aug  9 10:52:04 2006
+++ libicq2000-0.1/src/DirectClient.cpp	Wed Aug  9 10:53:26 2006
@@ -162,6 +162,8 @@
 
       m_recv.setLittleEndian();
       m_recv >> length;
+      if (length == 0)
+		return;
       if (length > Incoming_Packet_Limit) throw ParseException("Received too long incoming packet");
       if (m_recv.remains() < length) return; // waiting for more of the packet
 

--- plugins/icq/icqlogin.cpp.orig	Tue Nov  4 12:58:23 2003
+++ plugins/icq/icqlogin.cpp	Tue Nov  4 13:05:21 2003
@@ -139,7 +139,7 @@
         m_socket->writeBuffer.tlv(0x0017, 0x0014);
         m_socket->writeBuffer.tlv(0x0018, 0x0009);
         m_socket->writeBuffer.tlv(0x0019, 0x0000);
-        m_socket->writeBuffer.tlv(0x001A, 0x04E5);
+        m_socket->writeBuffer.tlv(0x001A, 0x0515);
         m_socket->writeBuffer.tlv(0x0014, 0x0000043DL);
         m_socket->writeBuffer.tlv(0x000f, "en");
         m_socket->writeBuffer.tlv(0x000e, "us");

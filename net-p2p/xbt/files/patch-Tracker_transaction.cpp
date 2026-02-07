--- Tracker/transaction.cpp.orig	2025-12-12 11:29:04 UTC
+++ Tracker/transaction.cpp
@@ -149,7 +149,8 @@ void Ctransaction::send_error(data_ref r, std::string_
 
 void Ctransaction::send(data_ref b)
 {
-  if (m_s.sendto(b, reinterpret_cast<const sockaddr*>(&m_a), sizeof(sockaddr_in)) != std::ssize(b))
+  if (m_s.sendto(b, reinterpret_cast<const sockaddr*>(&m_a), sizeof(sockaddr_in)) == -1)
     std::cerr << "send failed: " << Csocket::error2a(WSAGetLastError()) << std::endl;
-  srv_stats().sent_udp++;
+  else
+    srv_stats().sent_udp++;
 }

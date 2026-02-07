--- src/udpTracker.cpp.orig	2020-02-02 18:34:05 UTC
+++ src/udpTracker.cpp
@@ -169,7 +169,7 @@ namespace UDPT
 		yup = 1;
 		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&yup, 1);
 
-		r = bind (sock, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR_IN));
+		r = ::bind (sock, (SOCKADDR*)&recvAddr, sizeof(SOCKADDR_IN));
 
 		if (r == SOCKET_ERROR)
 		{
@@ -521,7 +521,7 @@ static int _isIANA_IP (uint32_t ip)
 			}
 		}
 
-		cout << ":: " << (void*)m_hton32(remote->sin_addr.s_addr) << ": " << m_hton16(remote->sin_port) << " ACTION=" << action << endl;
+		cout << ":: " << _ip_to_str(m_hton32(remote->sin_addr.s_addr)) << ":" << m_hton16(remote->sin_port) << " ACTION=" << action << endl;
 
 		if (action == 0 && r >= 16)
 			return UDPTracker::handleConnection (usi, remote, data);

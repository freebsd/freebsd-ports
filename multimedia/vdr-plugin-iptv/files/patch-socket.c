--- a/socket.c
+++ b/socket.c
@@ -57,9 +57,11 @@ bool cIptvSocket::OpenSocket(const int P
      // Allow multiple sockets to use the same PORT number
      ERROR_IF_FUNC(setsockopt(socketDesc, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0, "setsockopt(SO_REUSEADDR)",
                    CloseSocket(), return false);
+#ifndef __FreeBSD__
      // Allow packet information to be fetched
      ERROR_IF_FUNC(setsockopt(socketDesc, SOL_IP, IP_PKTINFO, &yes, sizeof(yes)) < 0, "setsockopt(IP_PKTINFO)",
                    CloseSocket(), return false);
+#endif
      // Bind socket
      memset(&sockAddr, '\0', sizeof(sockAddr));
      sockAddr.sin_family = AF_INET;
@@ -180,6 +182,7 @@ int cIptvUdpSocket::Read(unsigned char* 
      }
   else if (len > 0) {
      // Process auxiliary received data and validate source address
+#ifndef __FreeBSD__
      for (cmsg = CMSG_FIRSTHDR(&msgh); (streamAddr != INADDR_ANY) && (cmsg != NULL); cmsg = CMSG_NXTHDR(&msgh, cmsg)) {
          if ((cmsg->cmsg_level == SOL_IP) && (cmsg->cmsg_type == IP_PKTINFO)) {
             struct in_pktinfo *i = (struct in_pktinfo *)CMSG_DATA(cmsg);
@@ -189,6 +192,7 @@ int cIptvUdpSocket::Read(unsigned char* 
                }
             }
          }
+#endif
      if (BufferAddr[0] == TS_SYNC_BYTE)
         return len;
      else if (len > 3) {

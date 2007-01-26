--- lib/tcpconnectedsocket.cpp.orig	Thu Jun 29 22:01:48 2006
+++ lib/tcpconnectedsocket.cpp	Fri Jan 26 20:36:48 2007
@@ -149,8 +149,10 @@
 int TCPConnectedSocket::getMTU()
 {
     int s;
+    struct protoent *pent;
     socklen_t r = sizeof(int);
-    if (getsockopt(getDescriptor(), SOL_IP, IP_MTU, &s, &r) < 0) {
+    pent = getprotobyname ("ip");
+    if (getsockopt(getDescriptor(), ((pent != NULL) ? pent->p_proto : 0), IP_MTU, &s, &r) < 0) {
         s = -1;
     }
 

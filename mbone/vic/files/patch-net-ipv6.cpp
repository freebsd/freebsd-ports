--- net/net-ipv6.cpp.org	Mon Feb  4 17:51:46 2002
+++ net/net-ipv6.cpp	Mon Feb  4 17:52:08 2002
@@ -277,7 +277,7 @@
   p->sin6_family = AF_INET6;
   int len = sizeof(*p), result = 0;
 
-  if ((result = getsockname(ssock_, (struct sockaddr *)p, &len)) < 0) {
+  if ((result = getsockname(ssock_, (struct sockaddr *)p, (socklen_t *)&len)) < 0) {
     perror("getsockname");
     p->sin6_addr = in6addr_any;
     p->sin6_port = 0;
@@ -364,7 +364,7 @@
 		 * with bated breath.
 		 */
 #if defined(__FreeBSD__)
-                struct oipv6_mreq mr;
+                struct ipv6_mreq mr;
 #else
                 struct ipv6_mreq mr;
 #endif
@@ -522,7 +522,7 @@
 	sockaddr_in6 sfrom;
 	int fromlen = sizeof(sfrom);
 	int cc = ::recvfrom(fd, (char*)buf, len, 0,
-			    (sockaddr*)&sfrom, &fromlen);
+			    (sockaddr*)&sfrom, (socklen_t *)&fromlen);
 	if (cc < 0) {
 		if (errno != EWOULDBLOCK)
 			perror("recvfrom");

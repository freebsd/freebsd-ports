--- cSocket.cpp.orig	Wed May  7 20:21:33 2003
+++ cSocket.cpp	Thu Aug 26 18:53:39 2004
@@ -1180,7 +1180,7 @@
 	}}}
 // try to set our local externally visible address
 void	cSocket::setLocalExternalIP(struct in_addr new_addr) {{{
-	static struct in_addr	last_ip_seen = 0;
+	static struct in_addr	last_ip_seen;
 	static int		same_ip_count = 0;
 
 	if (new_addr.s_addr != last_ip_seen.s_addr) {

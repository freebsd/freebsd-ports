--- src/mod_extforward.c.orig	2013-09-29 07:35:49.552153230 +0200
+++ src/mod_extforward.c	2013-09-29 07:35:58.633202984 +0200
@@ -439,7 +439,6 @@
 #ifdef HAVE_IPV6
 		ipstr_to_sockaddr(srv, real_remote_addr, &sock);
 #else
-		UNUSED(addrs_left);
 		sock.ipv4.sin_addr.s_addr = inet_addr(real_remote_addr);
 		sock.plain.sa_family = (sock.ipv4.sin_addr.s_addr == 0xFFFFFFFF) ? AF_UNSPEC : AF_INET;
 #endif


$FreeBSD$

--- src/transports/udp6.c.orig	Fri Oct  1 01:38:25 2004
+++ src/transports/udp6.c	Fri Oct  1 01:39:15 2004
@@ -275,6 +275,7 @@
 #endif
     /* quick test of the packet, if failed, repeat! */
     if (size != ntohs(udp6m.size)) {
+      char * tmp = MALLOC(INET6_ADDRSTRLEN);
       LOG(LOG_WARNING,
 	  _("Packed received from %s:%d (UDP6) failed format check."),
 	  inet_ntop(AF_INET6,
@@ -282,6 +283,7 @@
 		    tmp,
 		    INET6_ADDRSTRLEN), 
 	  ntohs(incoming.sin6_port));
+      FREE(tmp);
       goto RETRY;
     }
     GNUNET_ASSERT(sizeof(struct in6_addr) == sizeof(IP6addr));

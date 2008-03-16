--- src/libs/zbxcomms/comms.c.orig	2007-12-17 04:18:59.000000000 -0900
+++ src/libs/zbxcomms/comms.c	2008-03-15 21:38:41.000000000 -0800
@@ -698,7 +698,7 @@
 
 	for(i = 0; i < s->num_socks; i++) {
 #if !defined(_WINDOWS)
-		if(s->sockets[i] > n)
+               if(s->sockets[i] + 1 > n)
 			n = s->sockets[i] + 1;
 #endif
 		if(FD_ISSET(s->sockets[i], &sock_set))

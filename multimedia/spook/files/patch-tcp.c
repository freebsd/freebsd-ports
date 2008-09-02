--- tcp.c.orig	2008-09-02 14:40:15.000000000 +0100
+++ tcp.c	2008-09-02 14:41:53.000000000 +0100
@@ -454,7 +454,7 @@
 				strerror( errno ) );
 
 	i = 1;
-	if( setsockopt( fd, SOL_TCP, TCP_NODELAY, &i, sizeof( i ) ) < 0 )
+	if( setsockopt( fd, IPPROTO_TCP, TCP_NODELAY, &i, sizeof( i ) ) < 0 )
 		spook_log( SL_INFO, "error setting TCP_NODELAY on socket: %s",
 				strerror( errno ) );
 

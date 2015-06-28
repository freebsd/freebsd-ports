--- tcp.c.orig	2004-12-29 02:33:21 UTC
+++ tcp.c
@@ -454,7 +454,7 @@ static void do_accept( struct event_info
 				strerror( errno ) );
 
 	i = 1;
-	if( setsockopt( fd, SOL_TCP, TCP_NODELAY, &i, sizeof( i ) ) < 0 )
+	if( setsockopt( fd, IPPROTO_TCP, TCP_NODELAY, &i, sizeof( i ) ) < 0 )
 		spook_log( SL_INFO, "error setting TCP_NODELAY on socket: %s",
 				strerror( errno ) );
 

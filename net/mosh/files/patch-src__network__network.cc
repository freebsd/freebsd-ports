--- ./src/network/network.cc.orig	2012-10-19 15:45:18.000000000 -0400
+++ ./src/network/network.cc	2012-10-23 18:15:42.000000000 -0400
@@ -158,13 +158,13 @@
 
   /* set diffserv values to AF42 + ECT */
   uint8_t dscp = 0x92;
-  if ( setsockopt( _fd, IPPROTO_IP, IP_TOS, &dscp, 1) < 0 ) {
+  if ( setsockopt( _fd, IPPROTO_IP, IP_TOS, &dscp, sizeof (dscp)) < 0 ) {
     //    perror( "setsockopt( IP_TOS )" );
   }
 
   /* request explicit congestion notification on received datagrams */
 #ifdef HAVE_IP_RECVTOS
-  char tosflag = true;
+  int tosflag = true;
   socklen_t tosoptlen = sizeof( tosflag );
   if ( setsockopt( _fd, IPPROTO_IP, IP_RECVTOS, &tosflag, tosoptlen ) < 0 ) {
     perror( "setsockopt( IP_RECVTOS )" );

diff -r c564b3055165 src/fping.c
--- src/fping.c	Tue Mar 05 08:13:11 2013 -0400
+++ src/fping.c	Tue Mar 05 08:45:33 2013 -0400
@@ -1572,7 +1572,11 @@
     n = sendto( s, buffer, ping_pkt_size, 0,
         ( struct sockaddr* )&h->saddr, sizeof( FPING_SOCKADDR ) );
 
-    if( n < 0 || n != ping_pkt_size )
+    if(( n < 0 || n != ping_pkt_size)
+#if defined( EHOSTDOWN )
+                                      && errno != EHOSTDOWN
+#endif
+                                                            )
     {
         if( verbose_flag || unreachable_flag )
         {

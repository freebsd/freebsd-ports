diff --git src/icmpv6.c src/icmpv6.c
index 90a41cc..9b123ce 100644
--- src/icmpv6.c
+++ src/icmpv6.c
@@ -205,7 +205,7 @@ void dump_icmpv6(packet_t *pkt)
     case ICMPV6_TYPE_NEIGHBORSOLICIT:
       /* Skip 4 unused bytes */
       if ( skip_packet_bytes (pkt,4) == 0 )
-         return 0;
+         return;
 
       /* Next 16 bytes are an IPv6 address */
       if (get_packet_bytes((u_int8_t *) &v6addr, pkt, 16) == 0)

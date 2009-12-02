--- bgpd/bgp_dump.c.orig	2009-07-28 17:35:45.000000000 +0100
+++ bgpd/bgp_dump.c	2009-12-02 05:46:16.000000000 +0000
@@ -850,8 +850,12 @@
   memset (&bgp_dump_updates, 0, sizeof (struct bgp_dump));
   memset (&bgp_dump_routes, 0, sizeof (struct bgp_dump));
 
+#ifdef notsufficient
   bgp_dump_obuf = stream_new (BGP_MAX_PACKET_SIZE + BGP_DUMP_MSG_HEADER
                               + BGP_DUMP_HEADER_SIZE);
+#else
+  bgp_dump_obuf = stream_new(16384);
+#endif
 
   install_node (&bgp_dump_node, config_write_bgp_dump);
 

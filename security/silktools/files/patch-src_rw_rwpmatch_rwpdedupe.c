--- src/rw/rwpmatch/rwpdedupe.c.orig	Sun Mar 19 23:57:23 2006
+++ src/rw/rwpmatch/rwpdedupe.c	Sun Mar 19 23:57:45 2006
@@ -782,13 +782,14 @@
     input_t *buffers,
     int index )
 {
+    pcap_pkt_t *pkt;
+    sk_link_err_t rv;
+    sk_link_item_t *node;
+
     assert( buffers != NULL );
     assert( index >= 0 );
     assert( index < g_input_count );
  
-    pcap_pkt_t *pkt;
-    sk_link_err_t rv;
-    sk_link_item_t *node;
     rv = skLinkGetHead( &node, buffers[index].head );
     if ( rv != SKLINK_OK ) {
         return NULL;
@@ -808,13 +809,14 @@
     input_t *buffers,
     int index )
 {
+    pcap_pkt_t *pkt;
+    sk_link_err_t rv;
+    sk_link_item_t *node;
+
     assert( buffers != NULL );
     assert( index >= 0 );
     assert( index < g_input_count );
     
-    pcap_pkt_t *pkt;
-    sk_link_err_t rv;
-    sk_link_item_t *node;
     rv = skLinkGetTail( &node, buffers[index].head );
     if ( rv != SKLINK_OK ) {
         return NULL;

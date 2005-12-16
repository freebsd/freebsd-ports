--- g10/keygen.c.orig	Tue Jun 21 21:22:17 2005
+++ g10/keygen.c	Fri Dec 16 11:03:19 2005
@@ -3244,11 +3244,13 @@
 write_keyblock( IOBUF out, KBNODE node )
 {
     for( ; node ; node = node->next ) {
+	if(!is_deleted_kbnode(node)) {
 	int rc = build_packet( out, node->pkt );
 	if( rc ) {
 	    log_error("build_packet(%d) failed: %s\n",
 			node->pkt->pkttype, g10_errstr(rc) );
 	    return G10ERR_WRITE_FILE;
+	}
 	}
     }
     return 0;

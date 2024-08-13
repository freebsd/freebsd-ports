--- lib/socket.c.orig	2024-02-05 23:51:38 UTC
+++ lib/socket.c
@@ -140,7 +140,7 @@ iscsi_add_to_outqueue(struct iscsi_context *iscsi, str
 	pdu->next = NULL;
 }
 
-void iscsi_decrement_iface_rr() {
+void iscsi_decrement_iface_rr(void) {
 	iface_rr--;
 }
 
@@ -531,7 +531,7 @@ iscsi_iovector_readv_writev(struct iscsi_context *iscs
 
 	if (pos < iovector->offset) {
 		iscsi_set_error(iscsi, "%s: iovector reset. pos(%d) is smaller than"
-				"current offset(%ld)", rw, pos, iovector->offset);
+				"current offset(%zd)", rw, pos, iovector->offset);
 		errno = EINVAL;
 		return -1;
 	}

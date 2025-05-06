--- lib/socket.c.orig	2025-05-03 00:02:42 UTC
+++ lib/socket.c
@@ -162,7 +162,7 @@ iscsi_add_to_outqueue(struct iscsi_context *iscsi, str
         return;
 }
 
-void iscsi_decrement_iface_rr() {
+void iscsi_decrement_iface_rr(void) {
         /* TODO QQQ use an atomic here */
 	iface_rr--;
 }
@@ -579,7 +579,7 @@ iscsi_iovector_readv_writev(struct iscsi_context *iscs
 
 	if (pos < iovector->offset) {
 		iscsi_set_error(iscsi, "%s: iovector reset. pos(%d) is smaller than"
-				"current offset(%ld)", rw, pos, iovector->offset);
+				"current offset(%zd)", rw, pos, iovector->offset);
 		errno = EINVAL;
 		return -1;
 	}

--- ./lib/socket.c.ORIG	2023-02-11 20:12:27.340472000 +0100
+++ ./lib/socket.c	2023-02-11 21:13:25.802721000 +0100
@@ -140,7 +140,7 @@
 	pdu->next = NULL;
 }
 
-void iscsi_decrement_iface_rr() {
+void iscsi_decrement_iface_rr(void) {
 	iface_rr--;
 }
 

Index: amd/rpc_fwd.c
===================================================================
--- amd/rpc_fwd.c	(revision 350048)
+++ amd/rpc_fwd.c	(revision 350049)
@@ -221,7 +221,7 @@
  * different address.
  */
 int
-fwd_packet(int type_id, char *pkt, int len, struct sockaddr_in *fwdto, struct sockaddr_in *replyto, opaque_t cb_arg, fwd_fun cb)
+fwd_packet(int type_id, char *pkt, int len, struct sockaddr_in *fwdto, struct sockaddr_in *replyto, opaque_t cb_arg, fwd_fun *cb)
 {
   rpc_forward *p;
   u_int *pkt_int;

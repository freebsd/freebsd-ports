--- ssh2transport.c.orig	2019-03-16 12:26:35 UTC
+++ ssh2transport.c
@@ -1781,6 +1781,7 @@ static void ssh2_transport_gss_update(struct ssh2_tran
     if (mins > 0 && s->gss_ctxt_lifetime <= mins * 60)
         s->gss_status |= GSS_CTXT_EXPIRES;
 }
+#endif /* NO_GSSAPI */
 
 ptrlen ssh2_transport_get_session_id(PacketProtocolLayer *ppl)
 {
@@ -1804,8 +1805,6 @@ void ssh2_transport_notify_auth_done(PacketProtocolLay
     s->rekey_class = RK_POST_USERAUTH;
     queue_idempotent_callback(&s->ppl.ic_process_queue);
 }
-
-#endif /* NO_GSSAPI */
 
 static bool ssh2_transport_get_specials(
     PacketProtocolLayer *ppl, add_special_fn_t add_special, void *ctx)

--- src/openvpn/multi.c.orig	2025-04-02 06:53:10 UTC
+++ src/openvpn/multi.c
@@ -3169,6 +3169,18 @@ multi_process_float(struct multi_context *m, struct mu
             goto done;
         }
 
+        /* It doesn't make sense to let a peer float to the address it already
+         * has, so we disallow it. This can happen if a DCO netlink notification
+         * gets lost and we miss a floating step.
+         */
+        if (m1->peer_id == m2->peer_id)
+        {
+            msg(M_WARN, "disallowing peer %" PRIu32 " (%s) from floating to "
+                "its own address (%s)",
+                m1->peer_id, tls_common_name(mi->context.c2.tls_multi, false),
+                mroute_addr_print(&mi->real, &gc));
+            goto done;
+        }
         msg(D_MULTI_MEDIUM, "closing instance %s", multi_instance_string(ex_mi, false, &gc));
         multi_close_instance(m, ex_mi, false);
     }
@@ -3301,6 +3313,17 @@ multi_process_incoming_dco(struct multi_context *m)
         {
             process_incoming_del_peer(m, mi, dco);
         }
+#if defined(TARGET_FREEBSD)
+        else if (dco->dco_message_type == OVPN_CMD_FLOAT_PEER)
+        {
+            ASSERT(mi->context.c2.link_socket);
+            extract_dco_float_peer_addr(mi->context.c2.link_socket->info.af,
+                                        &m->top.c2.from.dest,
+                                        (struct sockaddr *)&dco->dco_float_peer_ss);
+            multi_process_float(m, mi);
+            CLEAR(dco->dco_float_peer_ss);
+        }
+#endif /* if defined(TARGET_LINUX) || defined(TARGET_WIN32) */
         else if (dco->dco_message_type == OVPN_CMD_SWAP_KEYS)
         {
             tls_session_soft_reset(mi->context.c2.tls_multi);

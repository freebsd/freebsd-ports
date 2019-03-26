--- sshserver.c.orig	2019-03-16 12:26:36 UTC
+++ sshserver.c
@@ -50,7 +50,9 @@ struct server {
     PacketProtocolLayer *base_layer;
     ConnectionLayer *cl;
 
+#ifndef NO_GSSAPI
     struct ssh_connection_shared_gss_state gss_state;
+#endif
 };
 
 static void ssh_server_free_callback(void *vsrv);
@@ -245,9 +247,11 @@ Plug *ssh_server_plug(
     bufchain_init(&srv->out_raw);
     bufchain_init(&srv->dummy_user_input);
 
+#ifndef NO_GSSAPI
     /* FIXME: replace with sensible */
     srv->gss_state.libs = snew(struct ssh_gss_liblist);
     srv->gss_state.libs->nlibraries = 0;
+#endif
 
     return &srv->plug;
 }
@@ -297,7 +301,9 @@ static void ssh_server_free_callback(void *vsrv)
     conf_free(srv->conf);
     log_free(srv->logctx);
 
+#ifndef NO_GSSAPI
     sfree(srv->gss_state.libs);        /* FIXME: replace with sensible */
+#endif
 
     sfree(srv);
 
@@ -442,7 +448,12 @@ static void server_got_ssh_version(struct ssh_version_
             srv->conf, NULL, 0, NULL,
             ssh_verstring_get_remote(old_bpp),
             ssh_verstring_get_local(old_bpp),
-            &srv->gss_state, &srv->stats, transport_child_layer, true);
+#ifndef NO_GSSAPI
+            &srv->gss_state,
+#else
+            NULL,
+#endif
+            &srv->stats, transport_child_layer, true);
         ssh2_transport_provide_hostkeys(
             srv->base_layer, srv->hostkeys, srv->nhostkeys);
         if (userauth_layer)

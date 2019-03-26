--- ssh.c.orig	2019-03-16 12:26:35 UTC
+++ ssh.c
@@ -50,7 +50,9 @@ struct Ssh {
     ssh_sharing_state *connshare;
     bool attempting_connshare;
 
+#ifndef NO_GSSAPI
     struct ssh_connection_shared_gss_state gss_state;
+#endif
 
     char *savedhost;
     int savedport;
@@ -252,10 +254,18 @@ static void ssh_got_ssh_version(struct ssh_version_rec
                     conf_get_bool(ssh->conf, CONF_tryagent), username,
                     conf_get_bool(ssh->conf, CONF_change_username),
                     conf_get_bool(ssh->conf, CONF_try_ki_auth),
+#ifndef NO_GSSAPI
                     conf_get_bool(ssh->conf, CONF_try_gssapi_auth),
                     conf_get_bool(ssh->conf, CONF_try_gssapi_kex),
                     conf_get_bool(ssh->conf, CONF_gssapifwd),
-                    &ssh->gss_state);
+                    &ssh->gss_state
+#else
+                    false,
+                    false,
+                    false,
+                    NULL
+#endif
+                    );
                 ssh_connect_ppl(ssh, userauth_layer);
                 transport_child_layer = userauth_layer;
 
@@ -267,7 +277,11 @@ static void ssh_got_ssh_version(struct ssh_version_rec
                 ssh->fullhostname,
                 ssh_verstring_get_local(old_bpp),
                 ssh_verstring_get_remote(old_bpp),
+#ifndef NO_GSSAPI
                 &ssh->gss_state,
+#else
+                NULL,
+#endif
                 &ssh->stats, transport_child_layer, false);
             ssh_connect_ppl(ssh, ssh->base_layer);
 

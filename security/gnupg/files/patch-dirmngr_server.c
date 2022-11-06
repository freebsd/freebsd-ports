--- dirmngr/server.c.orig	2022-10-07 13:23:50 UTC
+++ dirmngr/server.c
@@ -3137,8 +3137,10 @@ start_command_handler (assuan_fd_t fd, unsigned int se
                ctrl->refcount);
   else
     {
+#if USE_LDAP
       ks_ldap_free_state (ctrl->ks_get_state);
       ctrl->ks_get_state = NULL;
+#endif /*USE_LDAP*/
       release_ctrl_ocsp_certs (ctrl);
       xfree (ctrl->server_local);
       dirmngr_deinit_default_ctrl (ctrl);

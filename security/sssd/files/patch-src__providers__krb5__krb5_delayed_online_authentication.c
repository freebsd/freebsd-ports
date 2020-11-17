diff --git src/providers/krb5/krb5_delayed_online_authentication.c src/providers/krb5/krb5_delayed_online_authentication.c
index 1cb7eade0..4aaeb84b2 100644
--- src/providers/krb5/krb5_delayed_online_authentication.c
+++ src/providers/krb5/krb5_delayed_online_authentication.c
@@ -328,6 +328,7 @@ errno_t init_delayed_online_authentication(struct krb5_ctx *krb5_ctx,
                                            struct tevent_context *ev)
 {
     int ret;
+#ifdef __linux__
     hash_table_t *tmp_table;
 
     ret = get_uid_table(krb5_ctx, &tmp_table);
@@ -347,6 +348,7 @@ errno_t init_delayed_online_authentication(struct krb5_ctx *krb5_ctx,
               "hash_destroy failed [%s].\n", hash_error_string(ret));
         return EFAULT;
     }
+#endif /* __linux__ */
 
     krb5_ctx->deferred_auth_ctx = talloc_zero(krb5_ctx,
                                           struct deferred_auth_ctx);

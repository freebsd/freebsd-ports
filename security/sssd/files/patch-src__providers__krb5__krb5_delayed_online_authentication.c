From eba3efda911eb0212a98353740e13ad619aaa282 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:20 +0100
Subject: [PATCH 09/25] patch-src__providers__krb5__krb5_delayed_online_authentication.c

---
 src/providers/krb5/krb5_delayed_online_authentication.c | 2 ++
 1 file changed, 2 insertions(+)

diff --git src/providers/krb5/krb5_delayed_online_authentication.c src/providers/krb5/krb5_delayed_online_authentication.c
index d5dea3b..da6b6bb 100644
--- src/providers/krb5/krb5_delayed_online_authentication.c
+++ src/providers/krb5/krb5_delayed_online_authentication.c
@@ -296,6 +296,7 @@ errno_t init_delayed_online_authentication(struct krb5_ctx *krb5_ctx,
                                            struct tevent_context *ev)
 {
     int ret;
+#ifdef __linux__
     hash_table_t *tmp_table;
 
     ret = get_uid_table(krb5_ctx, &tmp_table);
@@ -314,6 +315,7 @@ errno_t init_delayed_online_authentication(struct krb5_ctx *krb5_ctx,
         DEBUG(1, ("hash_destroy failed [%s].\n", hash_error_string(ret)));
         return EFAULT;
     }
+#endif /* __linux__ */
 
     krb5_ctx->deferred_auth_ctx = talloc_zero(krb5_ctx,
                                           struct deferred_auth_ctx);
-- 
1.8.0


From 144bf96dbd929248159bf932c1d3b5bccf451bee Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 10/34] patch-src__providers__ldap__ldap_child.c

---
 src/providers/ldap/ldap_child.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git src/providers/ldap/ldap_child.c src/providers/ldap/ldap_child.c
index f35d946..9a45cf5 100644
--- src/providers/ldap/ldap_child.c
+++ src/providers/ldap/ldap_child.c
@@ -206,7 +206,7 @@ static krb5_error_code ldap_child_get_tgt_sync(TALLOC_CTX *memctx,
         }
 
         realm_name = talloc_strdup(memctx, default_realm);
-        krb5_free_default_realm(context, default_realm);
+        free(default_realm);
         if (!realm_name) {
             krberr = KRB5KRB_ERR_GENERIC;
             goto done;
-- 
1.8.0


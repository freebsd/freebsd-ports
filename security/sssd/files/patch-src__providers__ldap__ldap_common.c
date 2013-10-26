From 5becc163a7101c94c84c4b7e330b62eb137c3bd7 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 11/34] patch-src__providers__ldap__ldap_common.c

---
 src/providers/ldap/ldap_common.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git src/providers/ldap/ldap_common.c src/providers/ldap/ldap_common.c
index f8b921a..84e51ae 100644
--- src/providers/ldap/ldap_common.c
+++ src/providers/ldap/ldap_common.c
@@ -1109,7 +1109,7 @@ sdap_gssapi_get_default_realm(TALLOC_CTX *mem_ctx)
     }
 
     realm = talloc_strdup(mem_ctx, krb5_realm);
-    krb5_free_default_realm(context, krb5_realm);
+    free(krb5_realm);
     if (!realm) {
         DEBUG(0, ("Out of memory\n"));
         goto done;
-- 
1.8.0


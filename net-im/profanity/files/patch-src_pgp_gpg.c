The gpgme_attr_t enums and their functions, which have been marked deprecated
since 2003, were removed in GpgME 2.0.0. The individual result structures
should be used instead.

--- src/pgp/gpg.c.orig	2023-07-14 05:39:30 UTC
+++ src/pgp/gpg.c
@@ -683,7 +683,7 @@ p_gpg_decrypt(const char* const cipher)
             error = gpgme_get_key(ctx, recipient->keyid, &key, 1);
 
             if (!error && key) {
-                const char* addr = gpgme_key_get_string_attr(key, GPGME_ATTR_EMAIL, NULL, 0);
+                const char* addr = key->uids->email;
                 if (addr) {
                     g_string_append(recipients_str, addr);
                 }

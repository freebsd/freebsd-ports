--- ./libsauth/src/dkimpublickey.c.org	2018-11-11 18:07:34.804563000 +0900
+++ ./libsauth/src/dkimpublickey.c	2018-11-11 17:48:47.356482000 +0900
@@ -398,11 +398,11 @@
     // compare key type key-k-tag declared and stored in key-p-tag
     switch (self->keytype) {
     case DKIM_KEY_TYPE_RSA:
-        if (EVP_PKEY_RSA != EVP_PKEY_type(self->pkey->type)) {
+        if (EVP_PKEY_RSA != EVP_PKEY_base_id(self->pkey)) {
             DkimLogPermFail
                 (policy,
                  "key-k-tag and key-p-tag doesn't match: domain=%s, keyalg=0x%x, keytype=0x%x",
-                 domain, self->keytype, EVP_PKEY_type(self->pkey->type));
+                 domain, self->keytype, EVP_PKEY_base_id(self->pkey));
             SETDEREF(dstat, DSTAT_PERMFAIL_PUBLICKEY_TYPE_MISMATCH);
             goto cleanup;
         }   // end if

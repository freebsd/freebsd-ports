Obtained from:	https://github.com/Ettercap/ettercap/commit/f71cd222712d6ecec6f086f3b8acca981e25f819

--- src/dissectors/ec_ssh.c.orig	2014-10-17 01:29:44.000000000 +0800
+++ src/dissectors/ec_ssh.c	2015-03-03 03:43:40.843089707 +0800
@@ -87,8 +87,8 @@
 
 struct des3_state
 {
-   des_key_schedule k1, k2, k3;
-   des_cblock iv1, iv2, iv3;
+   DES_key_schedule k1, k2, k3;
+   DES_cblock iv1, iv2, iv3;
 };
 
 struct blowfish_state 
@@ -608,13 +608,13 @@
    if (state == NULL) /* oops, couldn't allocate memory */
       return NULL;
 
-   des_set_key((void *)sesskey, (state->k1));
-   des_set_key((void *)(sesskey + 8), (state->k2));
+   DES_set_key((void *)sesskey, &(state->k1));
+   DES_set_key((void *)(sesskey + 8), &(state->k2));
 
    if (len <= 16)
-      des_set_key((void *)sesskey, (state->k3));
+      DES_set_key((void *)sesskey, &(state->k3));
    else
-      des_set_key((void *)(sesskey + 16), (state->k3));
+      DES_set_key((void *)(sesskey + 16), &(state->k3));
 
    memset(state->iv1, 0, 8);
    memset(state->iv2, 0, 8);
@@ -630,9 +630,9 @@
    dstate = (struct des3_state *)state;
    memcpy(dstate->iv1, dstate->iv2, 8);
 
-   des_ncbc_encrypt(src, dst, len, (dstate->k3), &dstate->iv3, DES_DECRYPT);
-   des_ncbc_encrypt(dst, dst, len, (dstate->k2), &dstate->iv2, DES_ENCRYPT);
-   des_ncbc_encrypt(dst, dst, len, (dstate->k1), &dstate->iv1, DES_DECRYPT);
+   DES_ncbc_encrypt(src, dst, len, &(dstate->k3), &dstate->iv3, DES_DECRYPT);
+   DES_ncbc_encrypt(dst, dst, len, &(dstate->k2), &dstate->iv2, DES_ENCRYPT);
+   DES_ncbc_encrypt(dst, dst, len, &(dstate->k1), &dstate->iv1, DES_DECRYPT);
 }
 
 static void swap_bytes(const u_char *src, u_char *dst, int n)

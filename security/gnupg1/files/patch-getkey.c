--- g10/getkey.c.orig	Tue Jul 29 03:34:41 2003
+++ g10/getkey.c	Thu Nov 27 18:54:55 2003
@@ -1655,6 +1655,11 @@
         if ( x ) /* mask it down to the actual allowed usage */
             key_usage &= x; 
     }
+
+    /* Type 20 Elgamal keys are not usable. */
+    if(pk->pubkey_algo==PUBKEY_ALGO_ELGAMAL)
+      key_usage=0;
+
     pk->pubkey_usage = key_usage;
 
     if ( !key_expire_seen ) {
@@ -1869,6 +1874,13 @@
         if ( x ) /* mask it down to the actual allowed usage */
             key_usage &= x; 
     }
+
+    /* Type 20 Elgamal subkeys or any subkey on a type 20 primary are
+       not usable. */
+    if(mainpk->pubkey_algo==PUBKEY_ALGO_ELGAMAL
+       || subpk->pubkey_algo==PUBKEY_ALGO_ELGAMAL)
+      key_usage=0;
+
     subpk->pubkey_usage = key_usage;
     
     p = parse_sig_subpkt (sig->hashed, SIGSUBPKT_KEY_EXPIRE, NULL);

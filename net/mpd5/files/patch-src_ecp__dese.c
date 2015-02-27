--- src/ecp_dese.c.orig	2013-06-11 09:00:00 UTC
+++ src/ecp_dese.c
@@ -89,11 +89,10 @@ DesConfigure(Bund b)
 {
   EcpState	const ecp = &b->ecp;
   DesInfo	const des = &ecp->des;
-  des_cblock	key;
+  DES_cblock	key;
 
-  des_check_key = FALSE;
-  des_string_to_key(ecp->key, &key);
-  des_set_key(&key, des->ks);
+  DES_string_to_key(ecp->key, &key);
+  DES_set_key(&key, &des->ks);
   des->xmit_seq = 0;
   des->recv_seq = 0;
 }
@@ -191,7 +190,7 @@ DesEncrypt(Bund b, Mbuf plain)
   {
     u_char	*const block = MBDATA(cypher) + DES_OVERHEAD + k;
 
-    des_cbc_encrypt(block, block, 8, des->ks, &des->xmit_ivec, TRUE);
+    DES_cbc_encrypt(block, block, 8, &des->ks, &des->xmit_ivec, TRUE);
     memcpy(des->xmit_ivec, block, 8);
   }
 
@@ -258,10 +257,10 @@ DesDecrypt(Bund b, Mbuf cypher)
   for (k = 0; k < clen; k += 8)
   {
     u_char	*const block = MBDATA(plain) + k;
-    des_cblock	next_ivec;
+    DES_cblock	next_ivec;
 
     memcpy(next_ivec, block, 8);
-    des_cbc_encrypt(block, block, 8, des->ks, &des->recv_ivec, FALSE);
+    DES_cbc_encrypt(block, block, 8, &des->ks, &des->recv_ivec, FALSE);
     memcpy(des->recv_ivec, next_ivec, 8);
   }
 

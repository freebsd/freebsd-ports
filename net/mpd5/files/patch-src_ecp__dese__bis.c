--- src/ecp_dese_bis.c.orig	2013-06-11 09:00:00 UTC
+++ src/ecp_dese_bis.c
@@ -89,11 +89,10 @@ DeseBisConfigure(Bund b)
 {
   EcpState	const ecp = &b->ecp;
   DeseBisInfo	const des = &ecp->desebis;
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
@@ -204,7 +203,7 @@ DeseBisEncrypt(Bund b, Mbuf plain)
   {
     u_char	*const block = MBDATA(cypher) + DES_OVERHEAD + k;
 
-    des_cbc_encrypt(block, block, 8, des->ks, &des->xmit_ivec, TRUE);
+    DES_cbc_encrypt(block, block, 8, &des->ks, &des->xmit_ivec, TRUE);
     memcpy(des->xmit_ivec, block, 8);
   }
 
@@ -271,10 +270,10 @@ DeseBisDecrypt(Bund b, Mbuf cypher)
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
 

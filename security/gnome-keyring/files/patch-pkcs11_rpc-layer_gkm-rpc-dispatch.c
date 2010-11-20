--- pkcs11/rpc-layer/gkm-rpc-dispatch.c.orig	2010-09-04 12:06:44.000000000 +0200
+++ pkcs11/rpc-layer/gkm-rpc-dispatch.c	2010-09-04 12:07:12.000000000 +0200
@@ -784,7 +784,7 @@ rpc_C_Finalize (CallState *cs)
 {
 	CK_SLOT_ID_PTR slots;
 	CK_ULONG n_slots, i;
-	CK_RV ret;
+	CK_RV ret = CKR_OK;
 
 	debug (("C_Finalize: enter"));
 

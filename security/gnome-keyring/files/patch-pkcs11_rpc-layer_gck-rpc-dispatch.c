--- pkcs11/rpc-layer/gck-rpc-dispatch.c.orig	2009-12-16 23:37:26.000000000 -0500
+++ pkcs11/rpc-layer/gck-rpc-dispatch.c	2009-12-16 23:38:10.000000000 -0500
@@ -783,7 +783,7 @@ rpc_C_Finalize (CallState *cs)
 {
 	CK_SLOT_ID_PTR slots;
 	CK_ULONG n_slots, i;
-	CK_RV ret;
+	CK_RV ret = CKR_OK;
 
 	debug (("C_Finalize: enter"));
 

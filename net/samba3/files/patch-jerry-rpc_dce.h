Index: source/include/rpc_dce.h
===================================================================
--- include/rpc_dce.h	(revision 842)
+++ include/rpc_dce.h	(working copy)
@@ -63,8 +63,10 @@
 #define NETSEC_AUTH_TYPE 0x44
 #define NETSEC_SIGN_SIGNATURE { 0x77, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00 }
 #define NETSEC_SEAL_SIGNATURE { 0x77, 0x00, 0x7a, 0x00, 0xff, 0xff, 0x00, 0x00 }
-#define RPC_AUTH_NETSEC_CHK_LEN 0x20
 
+#define RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN 	0x20
+#define RPC_AUTH_NETSEC_SIGN_ONLY_CHK_LEN 	0x18
+
 /* The 7 here seems to be required to get Win2k not to downgrade us
    to NT4.  Actually, anything other than 1ff would seem to do... */
 #define NETLOGON_NEG_AUTH2_FLAGS 0x000701ff

Index: source/rpc_parse/parse_rpc.c
===================================================================
--- rpc_parse/parse_rpc.c	(revision 842)
+++ rpc_parse/parse_rpc.c	(working copy)
@@ -1189,7 +1189,8 @@
 /*******************************************************************
 reads or writes an RPC_AUTH_NETSEC_CHK structure.
 ********************************************************************/
-BOOL smb_io_rpc_auth_netsec_chk(const char *desc, RPC_AUTH_NETSEC_CHK * chk,
+BOOL smb_io_rpc_auth_netsec_chk(const char *desc, int auth_len, 
+                                RPC_AUTH_NETSEC_CHK * chk,
 				prs_struct *ps, int depth)
 {
 	if (chk == NULL)
@@ -1198,10 +1199,19 @@
 	prs_debug(ps, depth, desc, "smb_io_rpc_auth_netsec_chk");
 	depth++;
 
-	prs_uint8s(False, "sig  ", ps, depth, chk->sig, sizeof(chk->sig));
-	prs_uint8s(False, "seq_num", ps, depth, chk->seq_num, sizeof(chk->seq_num));
-	prs_uint8s(False, "packet_digest", ps, depth, chk->packet_digest, sizeof(chk->packet_digest));
-	prs_uint8s(False, "confounder", ps, depth, chk->confounder, sizeof(chk->confounder));
+	if ( !prs_uint8s(False, "sig  ", ps, depth, chk->sig, sizeof(chk->sig)) )
+		return False;
+		
+	if ( !prs_uint8s(False, "seq_num", ps, depth, chk->seq_num, sizeof(chk->seq_num)) )
+		return False;
+		
+	if ( !prs_uint8s(False, "packet_digest", ps, depth, chk->packet_digest, sizeof(chk->packet_digest)) )
+		return False;
+	
+	if ( auth_len == RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN ) {
+		if ( !prs_uint8s(False, "confounder", ps, depth, chk->confounder, sizeof(chk->confounder)) )
+			return False;
+	}
 
 	return True;
 }

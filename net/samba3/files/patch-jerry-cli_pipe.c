Index: source/rpc_client/cli_pipe.c
===================================================================
--- rpc_client/cli_pipe.c	(revision 842)
+++ rpc_client/cli_pipe.c	(working copy)
@@ -332,13 +332,24 @@
 	if (cli->pipe_auth_flags & AUTH_PIPE_NETSEC) {
 		RPC_AUTH_NETSEC_CHK chk;
 
-		if (auth_len != RPC_AUTH_NETSEC_CHK_LEN) {
+		if ( (auth_len != RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN) 
+			&& (auth_len != RPC_AUTH_NETSEC_SIGN_ONLY_CHK_LEN)  ) 
+		{
 			DEBUG(0,("rpc_auth_pipe: wrong schannel auth len %d\n", auth_len));
 			return False;
 		}
 
-		if (!smb_io_rpc_auth_netsec_chk("schannel_auth_sign", 
-						&chk, &auth_verf, 0)) {
+		/* can't seal with no nonce */
+		if ( (cli->pipe_auth_flags & AUTH_PIPE_SEAL)
+			&& (auth_len != RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN)  )
+		{
+			DEBUG(0,("rpc_auth_pipe: sealing not supported with schannel auth len %d\n", auth_len));
+			return False;
+		}
+		
+
+		if (!smb_io_rpc_auth_netsec_chk("schannel_auth_sign", auth_len, &chk, &auth_verf, 0)) 
+		{
 			DEBUG(0, ("rpc_auth_pipe: schannel unmarshalling "
 				  "RPC_AUTH_NETSECK_CHK failed\n"));
 			return False;
@@ -918,7 +929,7 @@
 			auth_len = RPC_AUTH_NTLMSSP_CHK_LEN;
 		}
 		if (cli->pipe_auth_flags & AUTH_PIPE_NETSEC) {	
-			auth_len = RPC_AUTH_NETSEC_CHK_LEN;
+			auth_len = RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN;
 		}
 		auth_hdr_len = RPC_HDR_AUTH_LEN;
 	}
@@ -1034,8 +1045,9 @@
 				/* write auth footer onto the packet */
 				
 				parse_offset_marker = prs_offset(&sec_blob);
-				if (!smb_io_rpc_auth_netsec_chk("", &verf,
-								&sec_blob, 0)) {
+				if (!smb_io_rpc_auth_netsec_chk("", RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN, 
+					&verf, &sec_blob, 0)) 
+				{
 					prs_mem_free(&sec_blob);
 					return False;
 				}

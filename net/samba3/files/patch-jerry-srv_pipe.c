Index: source/rpc_server/srv_pipe.c
===================================================================
--- rpc_server/srv_pipe.c	(revision 842)
+++ rpc_server/srv_pipe.c	(working copy)
@@ -124,7 +124,7 @@
 	if(p->ntlmssp_auth_validated) {
 		data_space_available -= (RPC_HDR_AUTH_LEN + RPC_AUTH_NTLMSSP_CHK_LEN);
 	} else if(p->netsec_auth_validated) {
-		data_space_available -= (RPC_HDR_AUTH_LEN + RPC_AUTH_NETSEC_CHK_LEN);
+		data_space_available -= (RPC_HDR_AUTH_LEN + RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN);
 	}
 
 	/*
@@ -177,8 +177,8 @@
 	} else if (p->netsec_auth_validated) {
 		p->hdr.frag_len = RPC_HEADER_LEN + RPC_HDR_RESP_LEN +
 			data_len + ss_padding_len +
-			RPC_HDR_AUTH_LEN + RPC_AUTH_NETSEC_CHK_LEN;
-		p->hdr.auth_len = RPC_AUTH_NETSEC_CHK_LEN;
+			RPC_HDR_AUTH_LEN + RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN;
+		p->hdr.auth_len = RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN;
 	} else {
 		p->hdr.frag_len = RPC_HEADER_LEN + RPC_HDR_RESP_LEN + data_len;
 		p->hdr.auth_len = 0;
@@ -309,7 +309,8 @@
 			      SENDER_IS_ACCEPTOR,
 			      &verf, data, data_len + ss_padding_len);
 
-		smb_io_rpc_auth_netsec_chk("", &verf, &outgoing_pdu, 0);
+		smb_io_rpc_auth_netsec_chk("", RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN, 
+			&verf, &outgoing_pdu, 0);
 
 		p->netsec_auth.seq_num++;
 	}
@@ -1339,7 +1340,7 @@
 
 	auth_len = p->hdr.auth_len;
 
-	if (auth_len != RPC_AUTH_NETSEC_CHK_LEN) {
+	if (auth_len != RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN) {
 		DEBUG(0,("Incorrect auth_len %d.\n", auth_len ));
 		return False;
 	}
@@ -1384,7 +1385,9 @@
 		return False;
 	}
 
-	if(!smb_io_rpc_auth_netsec_chk("", &netsec_chk, rpc_in, 0)) {
+	if(!smb_io_rpc_auth_netsec_chk("", RPC_AUTH_NETSEC_SIGN_OR_SEAL_CHK_LEN, 
+		&netsec_chk, rpc_in, 0)) 
+	{
 		DEBUG(0,("failed to unmarshal RPC_AUTH_NETSEC_CHK.\n"));
 		return False;
 	}

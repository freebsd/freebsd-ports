--- source3/client/dnsbrowse.c.orig	2026-01-20 15:42:54 UTC
+++ source3/client/dnsbrowse.c
@@ -39,6 +39,7 @@ struct mdns_browse_state
 struct mdns_browse_state
 {
 	struct mdns_smbsrv_result *listhead; /* Browse result list head */
+	TALLOC_CTX * ctx;
 	int browseDone;
 
 };
@@ -64,7 +65,7 @@ static void do_smb_resolve(struct mdns_smbsrv_result *
 	struct timeval tv;
 	DNSServiceErrorType err;
 
-	TALLOC_CTX * ctx = talloc_tos();
+	TALLOC_CTX * ctx = talloc_new(NULL);
 
 	err = DNSServiceResolve(&mdns_conn_sdref, 0 /* flags */,
 		browsesrv->ifIndex,
@@ -91,7 +92,7 @@ static void do_smb_resolve(struct mdns_smbsrv_result *
 		}
 	}
 
-	TALLOC_FREE(fdset);
+	TALLOC_FREE(ctx);
 	DNSServiceRefDeallocate(mdns_conn_sdref);
 }
 
@@ -124,18 +125,19 @@ do_smb_browse_reply(DNSServiceRef sdRef, DNSServiceFla
 		return;
 	}
 
-	bresult = talloc_array(talloc_tos(), struct mdns_smbsrv_result, 1);
+	bresult = talloc_array(bstatep->ctx, struct mdns_smbsrv_result, 1);
 	if (bresult == NULL) {
 		return;
 	}
 
+	bresult->nextResult = NULL;
 	if (bstatep->listhead != NULL) {
 		bresult->nextResult = bstatep->listhead;
 	}
 
-	bresult->serviceName = talloc_strdup(talloc_tos(), serviceName);
-	bresult->regType = talloc_strdup(talloc_tos(), regtype);
-	bresult->domain = talloc_strdup(talloc_tos(), replyDomain);
+	bresult->serviceName = talloc_strdup(bstatep->ctx, serviceName);
+	bresult->regType = talloc_strdup(bstatep->ctx, regtype);
+	bresult->domain = talloc_strdup(bstatep->ctx, replyDomain);
 	bresult->ifIndex = interfaceIndex;
 	bstatep->listhead = bresult;
 }
@@ -151,9 +153,12 @@ int do_smb_browse(void)
 	DNSServiceRef mdns_conn_sdref = NULL;
 	DNSServiceErrorType err;
 
-	TALLOC_CTX * ctx = talloc_stackframe();
+	TALLOC_CTX * ctx = talloc_new(NULL);
 
 	ZERO_STRUCT(bstate);
+
+	bstate.ctx = ctx;
+	bstate.listhead = NULL;
 
 	err = DNSServiceBrowse(&mdns_conn_sdref, 0, 0, "_smb._tcp", "",
 			do_smb_browse_reply, &bstate);

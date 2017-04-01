--- source3/client/dnsbrowse.c.orig	2016-01-26 11:45:46 UTC
+++ source3/client/dnsbrowse.c
@@ -91,7 +91,7 @@ static void do_smb_resolve(struct mdns_s
 		}
 	}
 
-	TALLOC_FREE(fdset);
+	TALLOC_FREE(ctx);
 	DNSServiceRefDeallocate(mdns_conn_sdref);
 }
 

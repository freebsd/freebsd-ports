--- source3/client/dnsbrowse.c.orig	2017-01-11 07:55:15 UTC
+++ source3/client/dnsbrowse.c
@@ -91,7 +91,7 @@ static void do_smb_resolve(struct mdns_s
 		}
 	}
 
-	TALLOC_FREE(fdset);
+	TALLOC_FREE(ctx);
 	DNSServiceRefDeallocate(mdns_conn_sdref);
 }
 

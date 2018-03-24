--- source3/client/dnsbrowse.c.orig	2017-07-04 10:05:25 UTC
+++ source3/client/dnsbrowse.c
@@ -91,7 +91,7 @@ static void do_smb_resolve(struct mdns_s
 		}
 	}
 
-	TALLOC_FREE(fdset);
+	TALLOC_FREE(ctx);
 	DNSServiceRefDeallocate(mdns_conn_sdref);
 }
 

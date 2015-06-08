--- source3/client/dnsbrowse.c.orig	2013-11-12 10:20:03.145351798 +0100
+++ source3/client/dnsbrowse.c	2013-11-12 10:20:11.762761273 +0100
@@ -91,7 +91,7 @@
 		}
 	}
 
-	TALLOC_FREE(fdset);
+	TALLOC_FREE(ctx);
 	DNSServiceRefDeallocate(mdns_conn_sdref);
 }
 

--- bin/lookupd.c.orig	Tue Aug 10 14:37:18 2004
+++ bin/lookupd.c	Tue Aug 10 14:37:24 2004
@@ -174,7 +174,7 @@
 
 		for (i = 0; i < event_data->data; i++) {
 			struct sockaddr addr;
-			size_t addrlen;
+			socklen_t addrlen;
 
 			addrlen = sizeof(addr);
 			fd = accept(event_data->ident, &addr, &addrlen);

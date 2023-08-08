--- bin/varnishd/http2/cache_http2_hpack.c.orig	2023-03-15 08:52:02 UTC
+++ bin/varnishd/http2/cache_http2_hpack.c
@@ -135,10 +135,9 @@ h2h_addhdr(struct http *hp, char *b, size_t namelen, s
 			n = HTTP_HDR_URL;
 			disallow_empty = 1;
 
-			// rfc7540,l,3060,3071
-			if (((len > 0 && *b != '/') ||
-			    (len > 1 && *(b+1) == '/')) &&
-			    (strncmp(b, "*", len) != 0)) {
+			// rfc9113,l,2693,2705
+			if (len > 0 && *b != '/' &&
+			    strncmp(b, "*", len) != 0) {
 				VSLb(hp->vsl, SLT_BogoHeader,
 				    "Illegal :path pseudo-header %.*s",
 				    (int)len, b);

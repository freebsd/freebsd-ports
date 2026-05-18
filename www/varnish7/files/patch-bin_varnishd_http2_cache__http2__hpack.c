--- bin/varnishd/http2/cache_http2_hpack.c.orig	2025-08-20 12:50:25 UTC
+++ bin/varnishd/http2/cache_http2_hpack.c
@@ -171,7 +171,7 @@ h2h_addhdr(struct http *hp, struct h2h_decode *d)
 
 	/* Match H/2 pseudo headers */
 	/* XXX: Should probably have some include tbl for pseudo-headers */
-	if (!Tstrcmp(nm, ":method")) {
+	if (Tstreq(nm, ":method")) {
 		hdr.b = val.b;
 		n = HTTP_HDR_METHOD;
 		disallow_empty = 1;
@@ -181,13 +181,13 @@ h2h_addhdr(struct http *hp, struct h2h_decode *d)
 			if (!vct_istchar(*p))
 				return (H2SE_PROTOCOL_ERROR);
 		}
-	} else if (!Tstrcmp(nm, ":path")) {
+	} else if (Tstreq(nm, ":path")) {
 		hdr.b = val.b;
 		n = HTTP_HDR_URL;
 		disallow_empty = 1;
 
 		// rfc9113,l,2693,2705
-		if (Tlen(val) > 0 && val.b[0] != '/' && Tstrcmp(val, "*")) {
+		if (Tlen(val) > 0 && val.b[0] != '/' && !Tstreq(val, "*")) {
 			VSLb(hp->vsl, SLT_BogoHeader,
 			    "Illegal :path pseudo-header %.*s",
 			    (int)Tlen(val), val.b);
@@ -199,7 +199,7 @@ h2h_addhdr(struct http *hp, struct h2h_decode *d)
 			if (vct_islws(*p) || vct_isctl(*p))
 				return (H2SE_PROTOCOL_ERROR);
 		}
-	} else if (!Tstrcmp(nm, ":scheme")) {
+	} else if (Tstreq(nm, ":scheme")) {
 		/* XXX: What to do about this one? (typically
 		   "http" or "https"). For now set it as a normal
 		   header, stripping the first ':'. */
@@ -213,7 +213,7 @@ h2h_addhdr(struct http *hp, struct h2h_decode *d)
 			if (!vct_istchar(*p))
 				return (H2SE_PROTOCOL_ERROR);
 		}
-	} else if (!Tstrcmp(nm, ":authority")) {
+	} else if (Tstreq(nm, ":authority")) {
 		/* NB: we inject "host" in place of "rity" for
 		 * the ":authority" pseudo-header.
 		 */

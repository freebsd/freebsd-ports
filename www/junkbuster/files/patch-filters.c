--- filters.c.orig	Wed Dec 21 09:29:35 2005
+++ filters.c	Wed Dec 21 09:30:24 2005
@@ -581,7 +581,7 @@
 ij_untrusted_url(struct http_request *http, struct client_state *csp)
 {
 	int n;
-	char *hostport, *path, *p, *v[9];
+	char *hostport, *path, *referrer, *p, *v[9];
 	char buf[BUFSIZ];
 	struct url_spec **tl, *t;
 

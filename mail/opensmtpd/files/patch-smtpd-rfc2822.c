--- smtpd/rfc2822.c.orig	2018-05-01 13:33:10.000000000 +0000
+++ smtpd/rfc2822.c	2018-05-01 13:34:47.931554000 +0000
@@ -53,4 +53,7 @@
 	struct rfc2822_hdr_miss_cb	*hdr_miss_cb;
+ 	
+ 	if (!rp->in_hdr)
+		goto end;
 
 	TAILQ_FOREACH(hdr_cb, &rp->hdr_cb, next)
 	    if (strcasecmp(hdr_cb->name, rp->header.name) == 0) {
@@ -151,6 +152,8 @@
 		return;
 
 	header_callback(rp);
+
+	missing_headers_callback(rp);
 }
 
 void

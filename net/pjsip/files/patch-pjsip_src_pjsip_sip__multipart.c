--- pjsip/src/pjsip/sip_multipart.c.orig	2017-01-24 05:59:05 UTC
+++ pjsip/src/pjsip/sip_multipart.c
@@ -646,13 +646,15 @@ PJ_DEF(pjsip_msg_body*) pjsip_multipart_parse(pj_pool_
 
 	end_body = curptr;
 
-	/* The newline preceeding the delimiter is conceptually part of
-	 * the delimiter, so trim it from the body.
-	 */
-	if (*(end_body-1) == '\n')
-	    --end_body;
-	if (*(end_body-1) == '\r')
-	    --end_body;
+	if (end_body > start_body) {
+	    /* The newline preceeding the delimiter is conceptually part of
+	     * the delimiter, so trim it from the body.
+	     */
+	    if (*(end_body-1) == '\n')
+		--end_body;
+	    if (*(end_body-1) == '\r')
+		--end_body;
+	}
 
 	/* Now that we have determined the part's boundary, parse it
 	 * to get the header and body part of the part.

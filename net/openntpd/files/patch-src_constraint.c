--- src/constraint.c.orig	2015-03-14 21:24:11 UTC
+++ src/constraint.c
@@ -665,7 +665,7 @@ httpsdate_request(struct httpsdate *http
 		 * or ANSI C's asctime() - the latter doesn't include
 		 * the timezone which is required here.
 		 */
-		if (strptime(p, "%a, %d %h %Y %T %Z",
+		if (strptime(p, "%a, %d %h %Y %T GMT",
 		    &httpsdate->tls_tm) == NULL) {
 			log_warnx("unsupported date format");
 			free(line);

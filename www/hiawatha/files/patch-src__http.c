--- src/http.c.orig	2015-12-28 15:05:15 UTC
+++ src/http.c
@@ -845,8 +845,8 @@ int last_forwarded_ip(t_http_header *htt
 		/* Forwarded header
 		 */
 		begin = NULL;
-		while ((forwarded = strcasestr(forwarded, "for=")) == NULL) {
-			begin = forwarded;
+		while ((forwarded = strcasestr(forwarded, "for=")) != NULL) {
+			begin = forwarded + 4;
 			forwarded++;
 		}
 

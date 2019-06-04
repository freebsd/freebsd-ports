--- http.c.orig	2015-06-03 13:06:16 UTC
+++ http.c
@@ -113,6 +113,8 @@ read_from_server(CHANNEL fs, short ssl, 
             /* 204 No Content is not an error, message body is empty by definition, see RFC 2616 */
             if (reply_code == 204)
                 return 0;       /* zero bytes is correct */
+             if (accept_redirects && reply_code >= 300 && reply_code < 400)
+		return 0;
 
             if (!  (reply_code >= 200 && reply_code < 300) &&
                 ! ((reply_code >= 300 && reply_code < 400) && accept_redirects))

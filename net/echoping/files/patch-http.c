--- http.c.orig	2019-12-29 10:14:41 UTC
+++ http.c
@@ -6,7 +6,7 @@
 #include "HTParse.h"
 
 
-char            big_recvline[MAXTOREAD];
+static char	big_recvline[MAXTOREAD];
 
 char           *
 make_http_sendline(char *url, char *host, int port, int nocache)
@@ -113,6 +113,8 @@ read_from_server(CHANNEL fs, short ssl, boolean accept
             /* 204 No Content is not an error, message body is empty by definition, see RFC 2616 */
             if (reply_code == 204)
                 return 0;       /* zero bytes is correct */
+             if (accept_redirects && reply_code >= 300 && reply_code < 400)
+		return 0;
 
             if (!  (reply_code >= 200 && reply_code < 300) &&
                 ! ((reply_code >= 300 && reply_code < 400) && accept_redirects))

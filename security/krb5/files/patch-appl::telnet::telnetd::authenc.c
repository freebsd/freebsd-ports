--- appl/telnet/telnetd/authenc.c.orig	Wed Feb 28 14:06:51 2001
+++ appl/telnet/telnetd/authenc.c	Thu Jul 19 19:14:29 2001
@@ -43,8 +43,7 @@
 	int len;
 {
 	if (nfrontp + len < netobuf + BUFSIZ) {
-		memcpy((void *)nfrontp, (void *)str, len);
-		nfrontp += len;
+		output_datalen(str, len);
 		return(len);
 	}
 	return(0);

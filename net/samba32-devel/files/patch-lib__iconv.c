--- ./lib/iconv.c.orig	2008-09-18 06:49:02.000000000 +0000
+++ ./lib/iconv.c	2008-10-10 00:42:10.000000000 +0000
@@ -136,7 +136,7 @@
 			char **outbuf, size_t *outbytesleft)
 {
 	size_t ret = iconv((iconv_t)cd, 
-			   (char **)inbuf, inbytesleft, 
+			   inbuf, inbytesleft, 
 			   outbuf, outbytesleft);
 	if (ret == (size_t)-1) {
 		int saved_errno = errno;

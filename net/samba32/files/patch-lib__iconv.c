--- ./lib/iconv.c.orig	2009-06-22 21:05:38.000000000 +0000
+++ ./lib/iconv.c	2009-06-25 20:49:35.000000000 +0000
@@ -136,7 +136,7 @@
 			char **outbuf, size_t *outbytesleft)
 {
 	size_t ret = iconv((iconv_t)cd, 
-			   (char **)inbuf, inbytesleft, 
+			   inbuf, inbytesleft, 
 			   outbuf, outbytesleft);
 	if (ret == (size_t)-1) {
 		int saved_errno = errno;

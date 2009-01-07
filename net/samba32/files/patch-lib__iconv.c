--- ./lib/iconv.c.orig	2008-12-19 13:57:33.000000000 +0000
+++ ./lib/iconv.c	2009-01-06 17:10:53.000000000 +0000
@@ -136,7 +136,7 @@
 			char **outbuf, size_t *outbytesleft)
 {
 	size_t ret = iconv((iconv_t)cd, 
-			   (char **)inbuf, inbytesleft, 
+			   inbuf, inbytesleft, 
 			   outbuf, outbytesleft);
 	if (ret == (size_t)-1) {
 		int saved_errno = errno;

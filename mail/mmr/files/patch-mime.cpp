--- mime.cpp.orig	Tue Jan 24 16:58:33 2006
+++ mime.cpp	Sun Jul  9 23:46:48 2006
@@ -110,7 +110,7 @@
 	}
 	size_t available = obytesleft;
 	while ( ibytesleft > 0 ) {
-		iconv(iconv_ctx, &ibuf, &ibytesleft, &obuf, &obytesleft);
+		iconv(iconv_ctx, (const char **)&ibuf, &ibytesleft, &obuf, &obytesleft);
 
 		if ( ibytesleft > 0 ) {
 			if ( errno == EILSEQ ) {

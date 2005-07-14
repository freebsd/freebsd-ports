--- src/mString.cpp.orig	Tue Jul  5 03:03:22 2005
+++ src/mString.cpp	Tue Jul  5 03:04:15 2005
@@ -1223,7 +1223,7 @@
 	outbuf = &dst[0];
 	outbytesleft = dst.size();
 
-	if (iconv(UTF8ToLoc, &inbuf, &inbytesleft, 
+	if (iconv(UTF8ToLoc, (const char **)&inbuf, &inbytesleft, 
 				&outbuf, &outbytesleft) == -1) 
 	{
 		iconv_close(UTF8ToLoc);

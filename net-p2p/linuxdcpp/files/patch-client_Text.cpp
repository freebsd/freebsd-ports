--- client/Text.cpp.orig	Mon Feb  5 17:59:13 2007
+++ client/Text.cpp	Mon Feb  5 17:59:21 2007
@@ -309,7 +309,7 @@
 	char *outbuf = (char *)tmp.data();
 
 	while(inleft > 0) {
-		rv = iconv(cd, (char **)&inbuf, &inleft, &outbuf, &outleft);
+		rv = iconv(cd, &inbuf, &inleft, &outbuf, &outleft);
 		if(rv == (size_t)-1) {
 			size_t used = outbuf - tmp.data();
 			if(errno == E2BIG) {

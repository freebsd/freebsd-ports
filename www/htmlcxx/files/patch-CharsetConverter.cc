--- html/CharsetConverter.cc.orig	2012-09-19 14:05:35.000000000 +0800
+++ html/CharsetConverter.cc	2012-09-19 14:08:42.000000000 +0800
@@ -37,7 +37,7 @@
 
 	size_t ret;
 	while (1) {
-		ret = iconv(mIconvDescriptor, const_cast<char**>(&inbuf), &inbytesleft, &outbuf, &outbytesleft);
+		ret = iconv(mIconvDescriptor, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
 		if (ret == 0) break;
 		if (ret == (size_t)-1 && errno == E2BIG) return string();
 

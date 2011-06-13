--- icqprotocolplugin.cpp.orig	2011-06-10 23:51:17.870320723 +0400
+++ icqprotocolplugin.cpp	2011-06-10 23:54:37.586036961 +0400
@@ -673,7 +673,7 @@
 					size_t inbytesleft = mylength - 4;
 					size_t outbytesleft = BUFFER_SIZE - 1; /* Trailing \0 */
 					size_t result = iconv(iconv_utf16be_utf8,
-						&inbuf, &inbytesleft, &outbuf, &outbytesleft);
+						(const char**) &inbuf, &inbytesleft, &outbuf, &outbytesleft);
 
 					if (result == (size_t) -1)
 					{

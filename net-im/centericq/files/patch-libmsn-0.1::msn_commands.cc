--- libmsn-0.1/msn_commands.cc.orig	Thu Mar 28 13:07:35 2002
+++ libmsn-0.1/msn_commands.cc	Thu Mar 28 13:08:24 2002
@@ -442,7 +442,7 @@
 	     char **outbuf, size_t *outbytesleft)
 {
     while (*inbytesleft) {
-	iconv( handle, inbuf, inbytesleft, outbuf, outbytesleft);
+	iconv( handle, (const char**)inbuf, inbytesleft, outbuf, outbytesleft);
 	if (!*inbytesleft || !*outbytesleft)
 	    return;
 	/*got invalid seq - so replace it with '?' */

--- encoding.c.orig	2012-05-08 22:55:13.000000000 +0900
+++ encoding.c	2013-11-22 04:59:54.000000000 +0900
@@ -1789,13 +1789,18 @@
     const char *icv_in = (const char *) in;
     char *icv_out = (char *) out;
     int ret;
+    int one;
 
+    one = 1;
     if ((out == NULL) || (outlen == NULL) || (inlen == NULL) || (in == NULL)) {
         if (outlen != NULL) *outlen = 0;
         return(-1);
     }
     icv_inlen = *inlen;
     icv_outlen = *outlen;
+#ifdef ICONV_SET_ILSEQ_INVALID
+    iconvctl(cd, ICONV_SET_ILSEQ_INVALID, &one);
+#endif
     ret = iconv(cd, (ICONV_CONST char **) &icv_in, &icv_inlen, &icv_out, &icv_outlen);
     *inlen -= icv_inlen;
     *outlen -= icv_outlen;

--- pan/usenet-utils/mime-utils.cc.orig	2013-03-12 18:24:13.000000000 +0000
+++ pan/usenet-utils/mime-utils.cc	2013-03-12 18:25:19.000000000 +0000
@@ -77,7 +77,11 @@
       outbuf = out + converted;
       outleft = outlen - converted;
 
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+      converted = iconv (cd, &inbuf, &inleft, &outbuf, &outleft);
+#else
       converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
+#endif
 
       if (converted != (size_t) -1 && errno == 0) {
         /*

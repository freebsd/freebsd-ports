--- proxy/hdrs/MIME.cc.orig	2021-10-25 02:21:39.744130000 +0800
+++ proxy/hdrs/MIME.cc	2021-10-25 02:22:01.829261000 +0800
@@ -557,7 +557,7 @@
   return sum;
 }
 
-#ifdef DEBUG
+#ifdef ENABLE_MIME_SANITY_CHECK
 void
 mime_hdr_sanity_check(MIMEHdrImpl *mh)
 {

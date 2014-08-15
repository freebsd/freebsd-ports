--- dpkt.c.orig	2014-08-15 15:49:16.000000000 -0400
+++ dpkt.c	2014-08-15 15:49:34.000000000 -0400
@@ -54,7 +54,9 @@
     "UDPXY-UDS",
     "RAW"
 };
+#ifndef NDEBUG
 static const int UPXDT_LEN = sizeof(upxfmt_NAME) / sizeof(upxfmt_NAME[0]);
+#endif
 
 
 const char*

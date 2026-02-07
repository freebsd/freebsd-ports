--- ripng.h.orig	2014-07-25 00:06:01.000000000 +0200
+++ ripng.h	2014-07-25 00:06:18.000000000 +0200
@@ -15,7 +15,7 @@
 	struct in6_addr prefix;
 	u_int16_t tag;
 	u_int8_t len;
-	u_int8_t metric;
+	u_int16_t metric;
 } ripng_entry;
 
 /* Defines for which parts have been modified

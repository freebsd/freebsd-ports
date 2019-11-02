--- src/cdf.h.orig	2019-10-22 21:52:35 UTC
+++ src/cdf.h
@@ -48,6 +48,7 @@
 typedef int32_t cdf_secid_t;
 
 #define CDF_LOOP_LIMIT					10000
+#define CDF_ELEMENT_LIMIT				100000
 
 #define CDF_SECID_NULL					0
 #define CDF_SECID_FREE					-1

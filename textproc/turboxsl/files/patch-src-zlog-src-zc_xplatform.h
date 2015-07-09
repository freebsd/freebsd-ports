--- src/zlog/src/zc_xplatform.h.orig	2015-07-10 03:35:37.045763000 +0900
+++ src/zlog/src/zc_xplatform.h	2015-07-10 03:35:49.501573000 +0900
@@ -9,6 +9,7 @@
 #define __zc_xplatform_h
 
 #include <limits.h>
+#include <strings.h>
 
 #define ZLOG_INT32_LEN   sizeof("-2147483648") - 1
 #define ZLOG_INT64_LEN   sizeof("-9223372036854775808") - 1

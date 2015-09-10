--- src/zlog/src/zc_xplatform.h.orig	2015-07-02 18:01:10 UTC
+++ src/zlog/src/zc_xplatform.h
@@ -9,6 +9,7 @@
 #define __zc_xplatform_h
 
 #include <limits.h>
+#include <strings.h>
 
 #define ZLOG_INT32_LEN   sizeof("-2147483648") - 1
 #define ZLOG_INT64_LEN   sizeof("-9223372036854775808") - 1

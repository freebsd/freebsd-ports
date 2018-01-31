--- src/lib/common/common.h.orig	2018-01-28 08:03:58.996880000 -0800
+++ src/lib/common/common.h	2018-01-28 08:04:48.899097000 -0800
@@ -137,7 +137,7 @@
 #include <stddef.h>
 
 // if not c++0x, future proof code by allowing use of nullptr
-#ifndef nullptr
+#if __cplusplus < 201103L
 #	define nullptr NULL
 #endif
 

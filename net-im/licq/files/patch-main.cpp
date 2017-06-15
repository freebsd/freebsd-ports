--- src/main.cpp.orig	2014-06-01 19:16:42 UTC
+++ src/main.cpp
@@ -31,7 +31,6 @@
 
 #ifdef USE_SOCKS5
 #define SOCKS
-#define INCLUDE_PROTOTYPES
 extern "C" {
 #include <socks.h>
 }

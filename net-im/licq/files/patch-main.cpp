--- src/main.cpp.orig	Wed Jan 29 13:19:50 2003
+++ src/main.cpp	Wed Jan 29 13:20:13 2003
@@ -10,7 +10,6 @@
 
 #ifdef USE_SOCKS5
 #define SOCKS
-#define INCLUDE_PROTOTYPES
 extern "C" {
 #include <socks.h>
 }

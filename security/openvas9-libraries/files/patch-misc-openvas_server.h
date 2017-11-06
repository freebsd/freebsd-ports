--- misc/openvas_server.h.orig	2015-08-03 10:14:29 UTC
+++ misc/openvas_server.h
@@ -48,6 +48,7 @@ extern "C"
 #ifdef _WIN32
 #include <winsock2.h>
 #else
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #endif
 

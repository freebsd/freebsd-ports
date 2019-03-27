--- src/3rdparty/chromium/net/dns/dns_util.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/dns/dns_util.cc
@@ -28,6 +28,8 @@ const int kMaxLabelLength = 63;
 
 }  // namespace
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)

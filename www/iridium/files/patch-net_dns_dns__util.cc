--- net/dns/dns_util.cc.orig	2017-06-05 19:03:10 UTC
+++ net/dns/dns_util.cc
@@ -26,6 +26,8 @@ const int kMaxLabelLength = 63;
 
 }  // namespace
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)

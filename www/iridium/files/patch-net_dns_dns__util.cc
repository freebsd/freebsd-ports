--- net/dns/dns_util.cc.orig	2019-03-11 22:01:01 UTC
+++ net/dns/dns_util.cc
@@ -36,6 +36,8 @@ const uint16_t kFlagNamePointer = 0xc000;
 
 }  // namespace
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)

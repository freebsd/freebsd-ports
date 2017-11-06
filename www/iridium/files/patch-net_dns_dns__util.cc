--- net/dns/dns_util.cc.orig	2017-04-19 19:06:36 UTC
+++ net/dns/dns_util.cc
@@ -15,6 +15,8 @@
 #include "build/build_config.h"
 #include "net/base/address_list.h"
 
+#include <sys/socket.h>
+
 #if defined(OS_POSIX)
 #include <netinet/in.h>
 #if !defined(OS_NACL)

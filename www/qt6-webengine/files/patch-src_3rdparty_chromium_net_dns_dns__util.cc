--- src/3rdparty/chromium/net/dns/dns_util.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/net/dns/dns_util.cc
@@ -29,6 +29,8 @@
 #include "net/dns/public/util.h"
 #include "net/third_party/uri_template/uri_template.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <net/if.h>
 #include <netinet/in.h>

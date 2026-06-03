--- net/dns/dns_util.cc.orig	2026-05-09 18:09:27 UTC
+++ net/dns/dns_util.cc
@@ -27,6 +27,8 @@
 #include "net/dns/public/util.h"
 #include "net/third_party/uri_template/uri_template.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <net/if.h>
 #include <netinet/in.h>

--- net/dns/dns_util.cc.orig	2026-08-13 07:41:05 UTC
+++ net/dns/dns_util.cc
@@ -27,6 +27,8 @@
 #include "net/third_party/uri_template/uri_template.h"
 #include "third_party/abseil-cpp/absl/container/flat_hash_map.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <net/if.h>
 #include <netinet/in.h>

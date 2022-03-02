--- net/dns/dns_util.cc.orig	2022-02-28 16:54:41 UTC
+++ net/dns/dns_util.cc
@@ -28,6 +28,8 @@
 #include "third_party/abseil-cpp/absl/types/optional.h"
 #include "url/url_canon.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <netinet/in.h>
 #include <net/if.h>

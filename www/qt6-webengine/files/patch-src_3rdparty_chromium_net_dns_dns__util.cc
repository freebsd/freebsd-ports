--- src/3rdparty/chromium/net/dns/dns_util.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/dns/dns_util.cc
@@ -28,6 +28,8 @@
 #include "net/third_party/uri_template/uri_template.h"
 #include "third_party/abseil-cpp/absl/types/optional.h"
 
+#include <sys/socket.h>
+
 #if BUILDFLAG(IS_POSIX)
 #include <netinet/in.h>
 #include <net/if.h>

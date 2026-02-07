--- src/3rdparty/chromium/net/dns/address_sorter_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/net/dns/address_sorter_posix.cc
@@ -32,6 +32,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 #include <vector>

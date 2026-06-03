--- net/dns/address_sorter_posix.cc.orig	2026-01-14 08:33:23 UTC
+++ net/dns/address_sorter_posix.cc
@@ -29,6 +29,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 #include <vector>

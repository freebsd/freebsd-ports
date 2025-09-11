--- net/dns/address_sorter_posix.cc.orig	2025-09-10 13:22:16 UTC
+++ net/dns/address_sorter_posix.cc
@@ -33,6 +33,7 @@
 #include "net/dns/netinet_in_var_ios.h"
 #else
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #endif  // BUILDFLAG(IS_IOS)
 #endif
 #include <vector>

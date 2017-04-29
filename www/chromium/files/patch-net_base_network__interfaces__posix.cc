--- net/base/network_interfaces_posix.cc.orig	2017-04-19 19:06:36 UTC
+++ net/base/network_interfaces_posix.cc
@@ -9,7 +9,7 @@
 #include <memory>
 #include <set>
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 #include "net/base/network_interfaces_posix.h"
 #include <net/if.h>
 #include <netinet/in.h>
@@ -17,7 +17,7 @@
 
 namespace net {
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 namespace internal {
 
 // The application layer can pass |policy| defined in net_util.h to

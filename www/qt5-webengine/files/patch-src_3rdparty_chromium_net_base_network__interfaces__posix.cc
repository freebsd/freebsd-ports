Piggyback on the existing #ifdefs for the definitions of some stub functions.
--- src/3rdparty/chromium/net/base/network_interfaces_posix.cc.orig	2017-04-20 16:49:59 UTC
+++ src/3rdparty/chromium/net/base/network_interfaces_posix.cc
@@ -9,7 +9,7 @@
 
 #include "base/memory/scoped_ptr.h"
 
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

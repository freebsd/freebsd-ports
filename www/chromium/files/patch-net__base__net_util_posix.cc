--- net/base/net_util_posix.cc.orig	2015-01-24 20:40:37.161729000 +0100
+++ net/base/net_util_posix.cc	2015-01-24 20:41:01.962110000 +0100
@@ -23,8 +23,10 @@
 #if defined(OS_MACOSX)
 #include <ifaddrs.h>
 #else
+#if !defined(OS_BSD)
 #include "net/base/address_tracker_linux.h"
 #include "net/base/net_util_posix.h"
+#endif
 #endif  // OS_MACOSX
 #include <net/if.h>
 #include <netinet/in.h>
@@ -40,6 +42,7 @@
 
 namespace {
 
+#if !defined(OS_BSD)
 // The application layer can pass |policy| defined in net_util.h to
 // request filtering out certain type of interfaces.
 bool ShouldIgnoreInterface(const std::string& name, int policy) {
@@ -76,6 +79,7 @@
   }
   return false;
 }
+#endif
 
 #if defined(OS_MACOSX)
 
@@ -147,7 +151,7 @@
 }
 
 #endif                   // !defined(OS_IOS)
-#elif !defined(OS_NACL)  // OS_MACOSX
+#elif !defined(OS_NACL) && !defined(OS_BSD) // OS_MACOSX
 
 // Convert platform native IPv6 address attributes to net IP address
 // attributes and drop ones that can't be used by the application
@@ -192,6 +196,7 @@
 #endif
 }
 
+#if !defined(OS_BSD)
 bool GetNetworkListImpl(
     NetworkInterfaceList* networks,
     int policy,
@@ -265,13 +270,14 @@
   return true;
 }
 #endif
+#endif
 
 }  // namespace internal
 
 bool GetNetworkList(NetworkInterfaceList* networks, int policy) {
   if (networks == NULL)
     return false;
-#if defined(OS_NACL)
+#if defined(OS_NACL) || defined(OS_BSD)
   NOTIMPLEMENTED();
   return false;
 #elif !defined(OS_MACOSX)

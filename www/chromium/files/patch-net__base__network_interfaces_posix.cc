--- net/base/network_interfaces_posix.cc.orig	2015-09-03 11:04:58.534429000 -0400
+++ net/base/network_interfaces_posix.cc	2015-09-03 11:07:05.587031000 -0400
@@ -20,6 +20,7 @@
 #if !defined(OS_NACL)
 namespace internal {
 
+#if !defined(OS_BSD)
 // The application layer can pass |policy| defined in net_util.h to
 // request filtering out certain type of interfaces.
 bool ShouldIgnoreInterface(const std::string& name, int policy) {
@@ -33,6 +34,7 @@
 
   return false;
 }
+#endif
 
 // Check if the address is unspecified (i.e. made of zeroes) or loopback.
 bool IsLoopbackOrUnspecifiedAddress(const sockaddr* addr) {

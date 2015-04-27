--- net/base/net_util_posix.cc.orig	2015-04-19 16:44:32.000000000 +0200
+++ net/base/net_util_posix.cc	2015-04-19 16:45:29.000000000 +0200
@@ -20,6 +20,7 @@
 #if !defined(OS_NACL)
 namespace internal {
 
+#if !defined(OS_BSD)
 // The application layer can pass |policy| defined in net_util.h to
 // request filtering out certain type of interfaces.
 bool ShouldIgnoreInterface(const std::string& name, int policy) {
@@ -56,6 +57,7 @@
   }
   return false;
 }
+#endif
 
 }  // namespace internal
 #else   // OS_NACL

--- ./sync/util/get_session_name_linux.cc.orig	2014-04-24 22:35:50.000000000 +0200
+++ ./sync/util/get_session_name_linux.cc	2014-04-24 23:23:47.000000000 +0200
@@ -13,8 +13,9 @@
 namespace internal {
 
 std::string GetHostname() {
-  char hostname[HOST_NAME_MAX];
-  if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
+  int len = sysconf(_SC_HOST_NAME_MAX);
+  char hostname[len];
+  if (gethostname(hostname, len) == 0)  // Success.
     return hostname;
   return base::GetLinuxDistro();
 }

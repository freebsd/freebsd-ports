--- sync/util/get_session_name_linux.cc.orig	2013-08-16 23:53:51.000000000 +0300
+++ sync/util/get_session_name_linux.cc	2013-08-16 23:56:00.000000000 +0300
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

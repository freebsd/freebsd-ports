--- sync/util/get_session_name_linux.cc.orig	2016-03-25 13:04:51 UTC
+++ sync/util/get_session_name_linux.cc
@@ -13,8 +13,9 @@ namespace syncer {
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

--- components/sync/base/get_session_name_linux.cc.orig	2017-02-02 02:02:53 UTC
+++ components/sync/base/get_session_name_linux.cc
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

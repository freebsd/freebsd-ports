--- components/sync/base/get_session_name_linux.cc.orig	2016-10-06 04:02:17.000000000 +0300
+++ components/sync/base/get_session_name_linux.cc	2016-10-13 13:40:16.075193000 +0300
@@ -4,7 +4,7 @@
 
 #include "components/sync/base/get_session_name_linux.h"
 
-#include <limits.h>  // for HOST_NAME_MAX
+#include <limits.h>  // for _POSIX_HOST_NAME_MAX
 #include <unistd.h>  // for gethostname()
 
 #include "base/linux_util.h"
@@ -13,8 +13,8 @@
 namespace internal {
 
 std::string GetHostname() {
-  char hostname[HOST_NAME_MAX];
-  if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
+  char hostname[_POSIX_HOST_NAME_MAX];
+  if (gethostname(hostname, _POSIX_HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return base::GetLinuxDistro();
 }

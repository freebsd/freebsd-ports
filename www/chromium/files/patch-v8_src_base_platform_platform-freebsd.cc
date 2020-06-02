--- v8/src/base/platform/platform-freebsd.cc.orig	2020-05-13 18:41:59 UTC
+++ v8/src/base/platform/platform-freebsd.cc
@@ -6,6 +6,7 @@
 // parts, the implementation is in platform-posix.cc.
 
 #include <pthread.h>
+#include <pthread_np.h>
 #include <semaphore.h>
 #include <signal.h>
 #include <stdlib.h>
@@ -81,8 +82,8 @@ std::vector<OS::SharedLibraryAddress> OS::GetSharedLib
             lib_name = std::string(path);
           }
           result.push_back(SharedLibraryAddress(
-              lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
-              reinterpret_cast<uintptr_t>(map->kve_end)));
+              lib_name, static_cast<uintptr_t>(map->kve_start),
+              static_cast<uintptr_t>(map->kve_end)));
         }
 
         start += ssize;

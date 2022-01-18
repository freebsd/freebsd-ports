--- core/Common/3dParty/v8/v8/src/base/platform/platform-freebsd.cc.orig	2020-12-15 11:23:25 UTC
+++ core/Common/3dParty/v8/v8/src/base/platform/platform-freebsd.cc
@@ -82,8 +82,8 @@ std::vector<OS::SharedLibraryAddress> OS::GetSharedLib
             lib_name = std::string(path);
           }
           result.push_back(SharedLibraryAddress(
-              lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
-              reinterpret_cast<uintptr_t>(map->kve_end)));
+              lib_name, static_cast<uintptr_t>(map->kve_start),
+              static_cast<uintptr_t>(map->kve_end)));
         }
 
         start += ssize;

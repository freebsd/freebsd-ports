--- src/base/platform/platform-freebsd.cc.orig	2026-09-07 08:43:04 UTC
+++ src/base/platform/platform-freebsd.cc
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
@@ -116,6 +116,24 @@ Stack::StackSlot Stack::ObtainCurrentThreadStackStart(
     CHECK(!error);
     pthread_attr_destroy(&attr);
     return reinterpret_cast<uint8_t*>(base) + size;
+  }
+  pthread_attr_destroy(&attr);
+  return nullptr;
+}
+
+// static
+Stack::StackSlot Stack::ObtainCurrentThreadStackReservedLimit() {
+  pthread_attr_t attr;
+  int error;
+  pthread_attr_init(&attr);
+  error = pthread_attr_get_np(pthread_self(), &attr);
+  if (!error) {
+    void* base;
+    size_t size;
+    error = pthread_attr_getstack(&attr, &base, &size);
+    CHECK(!error);
+    pthread_attr_destroy(&attr);
+    return base;
   }
   pthread_attr_destroy(&attr);
   return nullptr;

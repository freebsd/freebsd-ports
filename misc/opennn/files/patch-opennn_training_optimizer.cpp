-- FreeBSD has no _SC_AVPHYS_PAGES; query the free memory with sysctl vm.stats.vm.v_free_count instead
-- Fixes the build on FreeBSD (use of undeclared identifier _SC_AVPHYS_PAGES)

--- opennn/training/optimizer.cpp.orig
+++ opennn/training/optimizer.cpp
@@ -8,6 +8,10 @@
 #elif defined(__linux__) || defined(__unix__)
 #include <unistd.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #if defined(_WIN32)
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
@@ -511,6 +515,19 @@
         available_bytes = (Index(vm_statistics.free_count) + Index(vm_statistics.inactive_count))
                         * Index(page_size);
 
+#elif defined(__FreeBSD__)
+
+        unsigned int free_pages = 0;
+        size_t free_pages_size = sizeof(free_pages);
+        const int sysctl_status = sysctlbyname("vm.stats.vm.v_free_count", &free_pages, &free_pages_size, nullptr, 0);
+        const long pages = sysctl_status == 0 ? long(free_pages) : 0;
+        const long page_size = sysconf(_SC_PAGE_SIZE);
+
+        throw_if(pages <= 0 || page_size <= 0,
+                 "Optimizer::get_maximum_batch_size: sysctl failed to query available RAM.");
+
+        available_bytes = Index(pages) * Index(page_size);
+
 #elif defined(__linux__) || defined(__unix__)
 
         const long pages = sysconf(_SC_AVPHYS_PAGES);

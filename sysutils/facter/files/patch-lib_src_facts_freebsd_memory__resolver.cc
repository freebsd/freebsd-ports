--- lib/src/facts/freebsd/memory_resolver.cc.orig	2017-07-10 14:30:58 UTC
+++ lib/src/facts/freebsd/memory_resolver.cc
@@ -0,0 +1,76 @@
+#include <internal/facts/freebsd/memory_resolver.hpp>
+#include <leatherman/execution/execution.hpp>
+#include <leatherman/logging/logging.hpp>
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <vm/vm_param.h>
+#include <unistd.h>
+
+using namespace std;
+using namespace leatherman::execution;
+
+namespace facter { namespace facts { namespace freebsd {
+
+    memory_resolver::data memory_resolver::collect_data(collection& facts)
+    {
+        data result;
+
+        size_t size;
+        int pagesize = getpagesize();
+
+        // Memory usage
+
+        unsigned long physmem;
+        size = sizeof(physmem);
+        if (0 == sysctlbyname("hw.physmem", &physmem, &size, NULL, 0)) {
+            result.mem_total = physmem;
+        }
+
+        unsigned int inactive_count = 0;
+        size = sizeof(inactive_count);
+        sysctlbyname("vm.stats.vm.v_inactive_count", &inactive_count, &size, NULL, 0);
+
+        unsigned int cache_count = 0;
+        size = sizeof(cache_count);
+        sysctlbyname("vm.stats.vm.v_cache_count", &cache_count, &size, NULL, 0);
+
+        unsigned int free_count = 0;
+        size = sizeof(free_count);
+        sysctlbyname("vm.stats.vm.v_free_count", &free_count, &size, NULL, 0);
+
+        long mem_free_page_count = inactive_count + cache_count + free_count;
+        result.mem_free = mem_free_page_count * pagesize;
+
+        // Swap usage
+
+        struct xswdev xsw;
+        size = sizeof(xsw);
+
+        int mib[16];
+        size_t mibsize;
+        mibsize = sizeof mib / sizeof mib[0];
+        if (sysctlnametomib("vm.swap_info", mib, &mibsize) == -1) {
+            LOG_DEBUG("sysctlnametomib() failed");
+        } else {
+            for (int n = 0; ; ++n) {
+                mib[mibsize] = n;
+                if (-1 == sysctl(mib, mibsize + 1, &xsw, &size, NULL, 0))
+                    break;
+
+                if (xsw.xsw_version != XSWDEV_VERSION) {
+                    LOG_DEBUG("xswdev version mismatch");
+                } else {
+                    result.swap_total += xsw.xsw_nblks;
+                    result.swap_free += xsw.xsw_nblks - xsw.xsw_used;
+                }
+            }
+
+            result.swap_free *= pagesize;
+            result.swap_total *= pagesize;
+        }
+
+        return result;
+    }
+
+}}}  // namespace facter::facts::freebsd

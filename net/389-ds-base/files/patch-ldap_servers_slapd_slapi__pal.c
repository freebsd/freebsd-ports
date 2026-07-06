--- ldap/servers/slapd/slapi_pal.c.orig	2026-06-28 11:15:27 UTC
+++ ldap/servers/slapd/slapi_pal.c
@@ -39,6 +39,9 @@
 #endif
 
 #include <sys/param.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 
 /* This warns if we have less than 128M avail */
 #define SPAL_WARN_MIN_BYTES ((uint64_t)134217728)
@@ -359,6 +362,62 @@ spal_meminfo_get()
 }
 
 
+#endif
+
+#ifdef __FreeBSD__
+static uint64_t
+_spal_freebsd_sysctl_value(const char *name)
+{
+    uint64_t value = 0;
+    size_t size = sizeof(value);
+
+    if (sysctlbyname(name, &value, &size, NULL, 0) != 0) {
+        return 0;
+    }
+
+    return value;
+}
+
+slapi_pal_meminfo *
+spal_meminfo_get()
+{
+    slapi_pal_meminfo *mi =
+        (slapi_pal_meminfo *)slapi_ch_calloc(1, sizeof(slapi_pal_meminfo));
+    struct rusage usage = {0};
+    uint64_t free_pages;
+    uint64_t inactive_pages;
+
+    mi->pagesize_bytes = (uint64_t)getpagesize();
+    mi->system_total_bytes =
+        _spal_freebsd_sysctl_value("hw.physmem");
+    mi->system_total_pages =
+        mi->system_total_bytes / mi->pagesize_bytes;
+
+    free_pages =
+        _spal_freebsd_sysctl_value("vm.stats.vm.v_free_count");
+    inactive_pages =
+        _spal_freebsd_sysctl_value("vm.stats.vm.v_inactive_count");
+
+    mi->system_available_pages = free_pages + inactive_pages;
+    mi->system_available_bytes =
+        mi->system_available_pages * mi->pagesize_bytes;
+
+    if (mi->system_available_bytes == 0) {
+        mi->system_available_bytes =
+            (mi->system_total_bytes * 8) / 10;
+        mi->system_available_pages =
+            mi->system_available_bytes / mi->pagesize_bytes;
+    }
+
+    if (getrusage(RUSAGE_SELF, &usage) == 0) {
+        mi->process_consumed_bytes =
+            (uint64_t)usage.ru_maxrss * 1024;
+        mi->process_consumed_pages =
+            mi->process_consumed_bytes / mi->pagesize_bytes;
+    }
+
+    return mi;
+}
 #endif
 
 #ifdef OS_solaris

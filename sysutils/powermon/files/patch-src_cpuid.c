--- src/cpuid.c.orig	2017-07-03 16:04:31 UTC
+++ src/cpuid.c
@@ -32,6 +32,9 @@
 #include <sys/cpuctl.h>
 #include <sys/errno.h>
 #include <sys/ioctl.h>
+#ifdef USE_LIBCPUID
+#include <libcpuid/libcpuid.h>
+#endif
 
 #include "cpuid.h"
 
@@ -176,6 +179,13 @@ void getcpuvendor(char *vendor, size_t vendor_len) {
  * Returns the CPU family.
  */
 const char *getcpufamily(void) {
+#ifdef USE_LIBCPUID
+	struct cpu_raw_data_t raw;
+	static struct cpu_id_t id;
+
+	return (cpuid_get_raw_data(&raw) == 0 && cpu_identify(&raw, &id) == 0)
+	? id.cpu_codename : "Unknown";
+#else
 	cpuctl_cpuid_count_args_t cpuid;
 
 	cpuid.level = 0x1;
@@ -240,6 +250,7 @@ const char *getcpufamily(void) {
 			return "Unknown";
 			break;
 	}
+#endif
 }
 
 

--- cargo-crates/sys-info-0.9.1/c/info.h.orig	2025-09-19 02:42:40 UTC
+++ cargo-crates/sys-info-0.9.1/c/info.h
@@ -1,6 +1,8 @@
 #ifndef INFO_H_
 #define INFO_H_
 
+#include <stdint.h>
+
 typedef struct LoadAvg {
         double one;
         double five;
@@ -28,10 +30,10 @@ unsigned int get_cpu_num(void);
 const char *get_os_release(void);
 
 unsigned int get_cpu_num(void);
-unsigned long get_cpu_speed(void);
+uint64_t get_cpu_speed(void);
 
 LoadAvg get_loadavg(void);
-unsigned long get_proc_total(void);
+uint64_t get_proc_total(void);
 
 MemInfo get_mem_info(void);
 DiskInfo get_disk_info(void);

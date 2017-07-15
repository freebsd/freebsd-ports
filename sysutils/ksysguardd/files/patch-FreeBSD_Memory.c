--- FreeBSD/Memory.c.orig	2015-08-12 07:03:15 UTC
+++ FreeBSD/Memory.c
@@ -37,13 +37,14 @@
 
 #define MEM_ACTIVE 0
 #define MEM_INACTIVE 1
-#define MEM_WIRED 2
-#define MEM_CACHED 3
-#define MEM_BUFFERED 4
-#define MEM_FREE 5
-#define MEM_TOTAL 6
+#define MEM_LAUNDRY 2
+#define MEM_WIRED 3
+#define MEM_CACHED 4
+#define MEM_BUFFERED 5
+#define MEM_FREE 6
+#define MEM_TOTAL 7
 
-static size_t memory_stats[7];
+static size_t memory_stats[8];
 
 #define SWAP_IN 0
 #define SWAP_OUT 1
@@ -133,6 +134,7 @@ int updateMemory(void)
      */
     GETPAGESYSCTL("vm.stats.vm.v_active_count", memory_stats[MEM_ACTIVE])
     GETPAGESYSCTL("vm.stats.vm.v_inactive_count", memory_stats[MEM_INACTIVE])
+    GETPAGESYSCTL("vm.stats.vm.v_laundry_count", memory_stats[MEM_LAUNDRY]) 
     GETPAGESYSCTL("vm.stats.vm.v_wire_count", memory_stats[MEM_WIRED])
     GETPAGESYSCTL("vm.stats.vm.v_cache_count", memory_stats[MEM_CACHED])
     GETPAGESYSCTL("vm.stats.vm.v_free_count", memory_stats[MEM_FREE])
@@ -184,7 +186,7 @@ void printMActiveInfo(const char* cmd)
 
 void printMInactive(const char* cmd)
 {
-    fprintf(CurrentClient, "%lu\n", memory_stats[MEM_INACTIVE]);
+    fprintf(CurrentClient, "%lu\n", memory_stats[MEM_INACTIVE] + memory_stats[MEM_LAUNDRY]);
 }
 
 void printMInactiveInfo(const char* cmd)
@@ -194,7 +196,7 @@ void printMInactiveInfo(const char* cmd)
 
 void printMApplication(const char* cmd)
 {
-    fprintf(CurrentClient, "%lu\n", memory_stats[MEM_ACTIVE] + memory_stats[MEM_INACTIVE]);
+    fprintf(CurrentClient, "%lu\n", memory_stats[MEM_ACTIVE] + memory_stats[MEM_INACTIVE] + memory_stats[MEM_LAUNDRY]);
 }
 
 void printMApplicationInfo(const char* cmd)

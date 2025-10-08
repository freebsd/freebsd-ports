--- apps/tlem/tlem.c.orig	2025-07-29 09:00:18 UTC
+++ apps/tlem/tlem.c
@@ -194,6 +194,7 @@ static void latency_reduction_stop(void)
 #include <stddef.h>
 #include <pthread.h>
 #include <sys/time.h>
+#include <sys/mman.h> /* MAP_ */
 
 // for route-mode
 #include <netinet/in.h>
@@ -214,7 +215,6 @@ static void latency_reduction_stop(void)
 
 #ifdef linux
 #define cpuset_t        cpu_set_t
-#include <sys/mman.h>
 #ifndef MAP_HUGETLB
 #define MAP_HUGETLB 0x40000
 #endif
@@ -3227,7 +3227,8 @@ avg_bw_parse(struct _qs *q, struct _cfg *dst, int ac, 
 static int
 avg_bw_parse(struct _qs *q, struct _cfg *dst, int ac, char *av[])
 {
-    double bw, token;
+    double token;
+    uint64_t bw;
     struct avgbw_arg *d;
 
     if (strcmp(av[0], "avg") != 0)
@@ -3239,7 +3240,7 @@ avg_bw_parse(struct _qs *q, struct _cfg *dst, int ac, 
         return 1; /* error */
     if (update_max_bw(q, bw))
         return 1;
-    token = (bw / 8) * (1UL << WSHIFT) / 1e9;
+    token = ((double)bw / 8) * (1UL << WSHIFT) / 1e9;
     dst->arg = ec_alloc(q, dst->ec, sizeof(*d));
     if (dst->arg == NULL)
         return 1;

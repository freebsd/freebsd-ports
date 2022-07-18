--- src/helpers/check_thread_affinity.c.orig	2021-11-16 11:26:03 UTC
+++ src/helpers/check_thread_affinity.c
@@ -47,29 +47,41 @@
 //
 // Author: Andreas Marek, MPCDF
 
-#define  _GNU_SOURCE
+//#define  _GNU_SOURCE
+#define __BSD_VISIBLE
 #include <stdio.h>
 #include <stdlib.h>
 #include <sched.h>
 #include <sys/types.h>
+#include <sys/_cpuset.h>
+#include <sys/cpuset.h>
 #include <unistd.h>
 
+#if FREEBSD_OSVERSION >= 1301000
+#  define HAVE_SCHED_FUNCS // sched_getcpu() and sched_getaffinity() were added in 13.1
+#endif
 
 void get_thread_affinity(int *cpu_id) {
+#if defined(HAVE_SCHED_FUNCS)
   *cpu_id = sched_getcpu();
+#else
+  *cpu_id = 0;
+#endif
 }
 
 void get_process_affinity(int cpu_id) {
-  cpu_set_t set;
+#if defined(HAVE_SCHED_FUNCS)
+  cpuset_t set;
   int ret, i;
   int cpu;
   cpu_id = 9999999 ;
-  ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
+  ret = sched_getaffinity(0, sizeof(cpuset_t), &set);
   for (i=0; i < CPU_SETSIZE; i++)
     {
       cpu = CPU_ISSET(i, &set);
       if (cpu == 1) { cpu_id = i; }
     }
+#endif
 }
 
 void get_process_id(int *process_id, int *pprocess_id) {

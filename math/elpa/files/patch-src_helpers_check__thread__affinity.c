--- src/helpers/check_thread_affinity.c.orig	2021-11-16 11:26:03 UTC
+++ src/helpers/check_thread_affinity.c
@@ -47,11 +47,14 @@
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
 
 
@@ -60,11 +63,11 @@ void get_thread_affinity(int *cpu_id) {
 }
 
 void get_process_affinity(int cpu_id) {
-  cpu_set_t set;
+  cpuset_t set;
   int ret, i;
   int cpu;
   cpu_id = 9999999 ;
-  ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);
+  ret = sched_getaffinity(0, sizeof(cpuset_t), &set);
   for (i=0; i < CPU_SETSIZE; i++)
     {
       cpu = CPU_ISSET(i, &set);

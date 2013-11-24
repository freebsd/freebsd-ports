--- src/plugins/task/cgroup/task_cgroup_cpuset.c.orig	2013-11-14 10:56:33.000000000 -0600
+++ src/plugins/task/cgroup/task_cgroup_cpuset.c	2013-11-14 11:10:51.000000000 -0600
@@ -59,7 +59,12 @@
 
 #ifdef HAVE_HWLOC
 #include <hwloc.h>
+#if !defined(__FreeBSD__)
 #include <hwloc/glibc-sched.h>
+#else
+// For cpuset
+#include <pthread_np.h>
+#endif
 
 # if HWLOC_API_VERSION <= 0x00010000
 /* After this version the cpuset structure and all it's functions
@@ -714,7 +719,7 @@
 	hwloc_obj_type_t req_hwtype;
 
 	size_t tssize;
-	cpu_set_t ts;
+	cpuset_t ts;
 
 	bind_type = job->cpu_bind_type ;
 	if (conf->task_plugin_param & CPU_BIND_VERBOSE ||
@@ -900,7 +905,7 @@
 
 		hwloc_bitmap_asprintf(&str, cpuset);
 
-		tssize = sizeof(cpu_set_t);
+		tssize = sizeof(cpuset_t);
 		if (hwloc_cpuset_to_glibc_sched_affinity(topology,cpuset,
 							 &ts,tssize) == 0) {
 			fstatus = SLURM_SUCCESS;

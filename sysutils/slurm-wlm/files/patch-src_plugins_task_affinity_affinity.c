--- src/plugins/task/affinity/affinity.c.orig	2021-05-12 20:23:20 UTC
+++ src/plugins/task/affinity/affinity.c
@@ -297,7 +297,7 @@ void reset_cpuset(cpu_set_t *new_mask, cpu_set_t *cur_
 	if (slurm_getaffinity(1, sizeof(full_mask), &full_mask)) {
 		/* Try to get full CPU mask from process init */
 		CPU_ZERO(&full_mask);
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && !defined(CPU_ALLOC)
 		CPU_OR(&full_mask, cur_mask);
 #else
 		CPU_OR(&full_mask, &full_mask, cur_mask);

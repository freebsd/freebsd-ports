--- x86info.h.orig	2008-12-30 22:20:56.000000000 +0300
+++ x86info.h	2008-12-30 22:21:20.000000000 +0300
@@ -183,6 +183,7 @@
 #include <unistd.h>
 static inline void bind_cpu(struct cpudata *cpu)
 {
+#if defined(__linux__)
 	cpu_set_t set;
 
 	if (sched_getaffinity(getpid(), sizeof(set), &set) == 0) {
@@ -190,6 +191,7 @@
 		CPU_SET(cpu->number, &set);
 		sched_setaffinity(getpid(), sizeof(set), &set);
 	}
+#endif
 }
 
 #endif /* _X86INFO_H */

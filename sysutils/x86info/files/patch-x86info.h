--- x86info.h.orig	2011-09-15 15:37:57.000000000 -0700
+++ x86info.h	2011-09-15 15:38:09.000000000 -0700
@@ -220,6 +220,7 @@
 
 #define _GNU_SOURCE
 #define __USE_GNU
+#ifdef __linux__
 #include <sched.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -233,5 +234,23 @@
 		sched_setaffinity(getpid(), sizeof(set), &set);
 	}
 }
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+static inline void bind_cpu(struct cpudata *cpu)
+{
+	cpuset_t set;
 
+	if (cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1,
+	    sizeof(set), &set) == 0) {
+		CPU_ZERO(&set);
+		CPU_SET(cpu->number, &set);
+		cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, -1,
+		    sizeof(set), &set);
+	}
+}
+#else
+# error "bind_cpu() is not implemented for this platform!"
+#endif
 #endif /* _X86INFO_H */

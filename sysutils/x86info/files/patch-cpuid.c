--- cpuid.c.orig	2010-09-08 12:19:56.000000000 -0700
+++ cpuid.c	2010-10-01 21:37:48.000000000 -0700
@@ -23,8 +23,16 @@
 #include <sched.h>
 
 #if defined(__FreeBSD__)
+# include <sys/param.h>
+# include <sys/cpuset.h>
 # include <sys/ioctl.h>
-# include <cpu.h>
+# if __FreeBSD_version < 701102
+#  define CPUDEV "/dev/cpu%d"
+#  include <cpu.h>
+# else
+#  define CPUDEV "/dev/cpuctl%d"
+#  include <sys/cpuctl.h>
+# endif
 #endif
 
 #include "x86info.h"
@@ -45,7 +53,11 @@
 	unsigned int *eax, unsigned int *ebx,
 	unsigned int *ecx, unsigned int *edx)
 {
+#if defined(__FreeBSD__)
+	cpuset_t set, tmp_set;
+#else
 	cpu_set_t set, tmp_set;
+#endif
 	unsigned int a = 0, b = 0, c = 0, d = 0;
 	int ret;
 
@@ -58,15 +70,25 @@
 	if (edx != NULL)
 		d = *edx;
 
+#if defined(__FreeBSD__)
+	ret = cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+	    -1, sizeof(set), &set);
+#else
 	ret = sched_getaffinity(getpid(), sizeof(set), &set);
+#endif
 	if (ret)
 		return ret;
 
 	/* man CPU_SET(3): To duplicate a CPU set, use memcpy(3) */
-	memcpy(&tmp_set, &set, sizeof(cpu_set_t));
+	memcpy(&tmp_set, &set, sizeof(tmp_set));
 	CPU_ZERO(&set);
 	CPU_SET(cpunr, &set);
+#if defined(__FreeBSD__)
+	ret = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+	    -1, sizeof(set), &set);
+#else
 	ret = sched_setaffinity(getpid(), sizeof(set), &set);
+#endif
 	if (ret)
 		return ret;
 
@@ -87,7 +109,12 @@
 		*edx = d;
 
 	/* Restore initial sched affinity */
+#if defined(__FreeBSD__)
+	ret = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+	    -1, sizeof(tmp_set), &tmp_set);
+#else
 	ret = sched_setaffinity(getpid(), sizeof(tmp_set), &tmp_set);
+#endif
 	if (ret)
 		return ret;
 	return 0;
@@ -102,11 +129,15 @@
 	unsigned int *ecx,
 	unsigned int *edx)
 {
-	static int nodriver=0;
+	static int nodriver=1;
 	char cpuname[20];
 	unsigned char buffer[16];
 	int fh;
+#if __FreeBSD_version < 701102
 	cpu_cpuid_args_t args;
+#else
+	cpuctl_cpuid_args_t args;
+#endif
 
 	if (nodriver == 1) {
 		if (native_cpuid(CPU_number, idx, eax,ebx,ecx,edx))
@@ -116,10 +147,14 @@
 
 	args.level = idx;
 	/* Ok, use the /dev/CPU interface in preference to the _up code. */
-	(void)snprintf(cpuname,18, "/dev/cpu%d", CPU_number);
+	(void)snprintf(cpuname,18, CPUDEV, CPU_number);
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
+#if __FreeBSD_version < 701102
 		if (ioctl(fh, CPU_CPUID, &args) != 0) {
+#else
+		if (ioctl(fh, CPUCTL_CPUID, &args) != 0) {
+#endif
 			perror(cpuname);
 			exit(EXIT_FAILURE);
 		}
@@ -134,8 +169,6 @@
 	} else {
 		/* Something went wrong, just do UP and hope for the best. */
 		nodriver = 1;
-		if (!silent && nrCPUs != 1)
-			perror(cpuname);
 		if (native_cpuid(CPU_number, idx, eax,ebx,ecx,edx)) {
 			printf("%s", NATIVE_CPUID_FAILED_MSG);
 			used_UP = 1;
@@ -187,7 +220,7 @@
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
 #ifndef S_SPLINT_S
-		lseek64(fh, (off64_t)idx, SEEK_CUR);
+		lseek(fh, (off_t)idx, SEEK_CUR);
 #endif
 		if (read(fh, &buffer[0], CPUID_CHUNK_SIZE) == -1) {
 			perror(cpuname);

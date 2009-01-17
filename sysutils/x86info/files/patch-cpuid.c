--- cpuid.c.orig	2008-12-16 22:09:47.000000000 +0300
+++ cpuid.c	2008-12-30 22:36:09.000000000 +0300
@@ -23,8 +23,15 @@
 #include <sched.h>
 
 #if defined(__FreeBSD__)
+# include <sys/param.h>
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
@@ -33,7 +40,9 @@
 	unsigned int *eax, unsigned int *ebx,
 	unsigned int *ecx, unsigned int *edx)
 {
+#if defined(__linux__)
 	cpu_set_t set;
+#endif
 	unsigned int a = 0, b = 0, c = 0, d = 0;
 
 	if (eax != NULL)
@@ -45,11 +54,13 @@
 	if (edx != NULL)
 		d = *edx;
 
+#if defined(__linux__)
 	if (sched_getaffinity(getpid(), sizeof(set), &set) == 0) {
 		CPU_ZERO(&set);
 		CPU_SET(cpunr, &set);
 		sched_setaffinity(getpid(), sizeof(set), &set);
 	}
+#endif
 
 	asm("cpuid"
 		: "=a" (a),
@@ -79,7 +90,11 @@
 	char cpuname[20];
 	unsigned char buffer[16];
 	int fh;
+#if __FreeBSD_version < 701102
 	cpu_cpuid_args_t args;
+#else
+	cpuctl_cpuid_args_t args;
+#endif
 
 	if (nodriver == 1) {
 		native_cpuid(CPU_number, idx, eax,ebx,ecx,edx);
@@ -88,10 +103,14 @@
 
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
@@ -106,8 +125,6 @@
 	} else {
 		/* Something went wrong, just do UP and hope for the best. */
 		nodriver = 1;
-		if (!silent && nrCPUs != 1)
-			perror(cpuname);
 		used_UP = 1;
 		native_cpuid(CPU_number, idx, eax,ebx,ecx,edx);
 		return;
@@ -154,7 +171,7 @@
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
 #ifndef S_SPLINT_S
-		lseek64(fh, (off64_t)idx, SEEK_CUR);
+		lseek(fh, (off_t)idx, SEEK_CUR);
 #endif
 		if (read(fh, &buffer[0], CPUID_CHUNK_SIZE) == -1) {
 			perror(cpuname);

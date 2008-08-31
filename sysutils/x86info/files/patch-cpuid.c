--- cpuid.c.orig	2007-11-27 03:37:20.000000000 +0300
+++ cpuid.c	2008-08-09 23:02:57.000000000 +0400
@@ -21,8 +21,15 @@
 #include <errno.h>
 
 #if defined(__FreeBSD__)
+# include <sys/param.h>
 # include <sys/ioctl.h>
-# include <cpu.h>
+# if __FreeBSD_version < 800042
+#  define CPUDEV "/dev/cpu%d"
+#  include <cpu.h>
+# else
+#  define CPUDEV "/dev/cpuctl%d"
+#  include <sys/cpuctl.h>
+# endif
 #endif
 
 #include "x86info.h"
@@ -38,7 +45,11 @@
 	char cpuname[20];
 	unsigned char buffer[16];
 	int fh;
+#if __FreeBSD_version < 800042
 	cpu_cpuid_args_t args;
+#else
+	cpuctl_cpuid_args_t args;
+#endif
 
 	if (nodriver==1) {
 		cpuid_UP(idx, eax, ebx, ecx, edx);
@@ -47,10 +58,14 @@
 
 	args.level = idx;
 	/* Ok, use the /dev/CPU interface in preference to the _up code. */
-	(void)snprintf(cpuname,18, "/dev/cpu%d", CPU_number);
+	(void)snprintf(cpuname,18, CPUDEV, CPU_number);
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
+#if __FreeBSD_version < 800042
 		if (ioctl(fh, CPU_CPUID, &args) != 0) {
+#else
+		if (ioctl(fh, CPUCTL_CPUID, &args) != 0) {
+#endif
 			perror(cpuname);
 			exit(EXIT_FAILURE);
 		}
@@ -107,7 +122,7 @@
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
 #ifndef S_SPLINT_S
-		lseek64(fh, (off64_t)idx, SEEK_CUR);
+		lseek(fh, (off_t)idx, SEEK_CUR);
 #endif
 		if (read(fh, &buffer[0], CPUID_CHUNK_SIZE) == -1) {
 			perror(cpuname);

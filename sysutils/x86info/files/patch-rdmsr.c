--- rdmsr.c.orig	2008-12-16 22:09:47.000000000 +0300
+++ rdmsr.c	2008-12-30 22:11:46.000000000 +0300
@@ -17,8 +17,15 @@
 #include "x86info.h"
 
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
 
 #if defined(__FreeBSD__)
@@ -30,12 +37,16 @@
 	unsigned long lo, hi;
 	int fh;
 	static int nodriver=0;
+#if __FreeBSD_version < 701102
 	cpu_msr_args_t args;
+#else
+	cpuctl_msr_args_t args;
+#endif
 
 	if (nodriver==1)
 		return 0;
 
-	(void)snprintf(cpuname, sizeof(cpuname), "/dev/cpu%d", cpu);
+	(void)snprintf(cpuname, sizeof(cpuname), CPUDEV, cpu);
 
 	fh = open(cpuname, O_RDONLY);
 	if (fh==-1) {
@@ -46,7 +57,11 @@
 	}
 
 	args.msr = idx;
-	if (ioctl(fh, CPU_RDMSR, &args) != 0) {
+#if __FreeBSD_version < 701102
+	if (ioctl(fh, CPU_RDMSR, &args) != 0) {                                 
+#else
+	if (ioctl(fh, CPUCTL_RDMSR, &args) != 0) {                                 
+#endif
 		if (close(fh) == -1) {
 			perror("close");
 			exit(EXIT_FAILURE);

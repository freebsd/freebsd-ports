--- lsmsr.c.orig	2009-02-06 20:10:58.000000000 +0300
+++ lsmsr.c	2009-02-09 01:51:49.000000000 +0300
@@ -31,6 +31,18 @@
 #include "AMD/fam10h.h"
 #include "generic_msr.h"
 
+#if defined(__FreeBSD__)
+# include <sys/param.h>
+# include <sys/ioctl.h>
+# if __FreeBSD_version < 701102
+#  define CPUDEV "/dev/cpu%d"
+#  include <cpu.h>
+# else
+#  define CPUDEV "/dev/cpuctl%d"
+#  include <sys/cpuctl.h>
+# endif
+#endif
+
 /* Todos:
  * - add (list and eventually write) support for write-only MSR
  * - add decoding support for bit fields
@@ -117,6 +129,29 @@
 	fprintf(stdout, "%s version %s\n", g.prog, VERSION);
 }
 
+#if defined(__FreeBSD__)
+
+int get_msr_val(unsigned int msr, unsigned long long *val)
+{
+#if __FreeBSD_version < 701102
+	cpu_msr_args_t args;
+#else   
+	cpuctl_msr_args_t args;
+#endif
+
+	args.msr = msr;
+#if __FreeBSD_version < 701102
+	if (ioctl(g.fd, CPU_RDMSR, &args) != 0) {
+#else
+	if (ioctl(g.fd, CPUCTL_RDMSR, &args) != 0) {
+#endif
+		return 0;
+	}
+	*val = args.data;
+
+	return 0;
+}
+#else /* !__FreeBSD__ */
 static int get_msr_val(unsigned int msr, unsigned long long *val)
 {
 	off64_t off;
@@ -142,11 +177,17 @@
 	return 0;
 }
 
+#endif
+
 static int open_dev(int cpu)
 {
 	char s[20];
 
+#ifdef __FreeBSD__
+	snprintf(s, sizeof(s), CPUDEV, cpu);
+#else
 	snprintf(s, sizeof(s), "/dev/cpu/%d/msr", cpu);
+#endif
 	g.fd = open(s, O_RDONLY);
 	if (g.fd < 0)
 		fprintf(stderr, "could not open device %s: %s\n", s,

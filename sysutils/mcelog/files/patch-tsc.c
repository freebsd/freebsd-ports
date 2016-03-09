--- tsc.c.orig	2016-02-10 18:38:43 UTC
+++ tsc.c
@@ -15,6 +15,12 @@
    on your Linux system; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA */
 #define _GNU_SOURCE 1
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <machine/cpufunc.h>
+#include <machine/specialreg.h>
+#endif
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -46,6 +52,7 @@ static int fmt_tsc(char **buf, u64 tsc, 
 	return 0;
 }
 
+#ifdef __Linux__
 static double cpufreq_mhz(int cpu, double infomhz)
 {
 	double mhz;
@@ -68,12 +75,29 @@ static double cpufreq_mhz(int cpu, doubl
 	fclose(f);
 	return mhz;
 }
+#endif
+
+#ifdef __FreeBSD__
+static double cpufreq_mhz(int cpu, double infomhz)
+{
+	double mhz;
+	uint64_t freq;
+	size_t len;
+
+	len = sizeof(freq);
+	if (sysctlbyname("machdep.tsc_freq", &freq, &len, NULL, 0) < 0)
+		return infomhz;
+	mhz = freq / 1000000.0;
+	return mhz;
+}
+#endif
 
 int decode_tsc_forced(char **buf, double mhz, u64 tsc)
 {
 	return fmt_tsc(buf, tsc, mhz);
 }
 
+#ifdef __Linux__
 static int deep_sleep_states(int cpu)
 {
 	int ret;
@@ -132,6 +156,41 @@ static int tsc_reliable(int cputype, int
 		return 0;
 	return 1;
 }
+#endif
+
+#ifdef __FreeBSD__
+/* Try to figure out if this CPU has a somewhat reliable TSC clock */
+static int tsc_reliable(int cputype, int cpunum)
+{
+	u_int regs[4];
+	u_int cpu_id, amd_pminfo;
+
+	if (cputype != CPU_K8 && !is_intel_cpu(cputype))
+		return 0;
+
+	do_cpuid(0, regs);
+	cpu_id = regs[1];
+	do_cpuid(0x80000000, regs);
+	if (regs[0] >= 0x80000007) {
+		do_cpuid(0x80000007, regs);
+		amd_pminfo = regs[3];
+	} else
+		amd_pminfo = 0;
+
+	if (amd_pminfo & AMDPM_TSC_INVARIANT)
+		return 1;
+	if (is_intel_cpu(cputype)) {
+		if (CPUID_TO_FAMILY(cpu_id) >= 0x10 ||
+		    cpu_id == 0x60fb2)
+			return 1;
+	} else if ((CPUID_TO_FAMILY(cpu_id) == 0x6 &&
+		CPUID_TO_MODEL(cpu_id) >= 0xe) ||
+	    (CPUID_TO_FAMILY(cpu_id) == 0xf && CPUID_TO_MODEL(cpu_id) >= 0x3))
+		return 1;
+
+	return 0;
+}
+#endif
 
 int decode_tsc_current(char **buf, int cpunum, enum cputype cputype, double mhz, 
 		       unsigned long long tsc)

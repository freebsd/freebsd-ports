--- src/utils/os_divers.c.orig	2012-04-04 18:47:33.000000000 +0400
+++ src/utils/os_divers.c	2013-10-12 14:25:42.047109095 +0400
@@ -1533,6 +1533,123 @@
 	return 1;
 }
 
+#elif defined GPAC_CONFIG_FREEBSD
+
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/user.h>
+
+#define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
+int getsysctl(const char *name, void *ptr, size_t len) {
+	size_t nlen = len;
+	if (sysctlbyname(name, ptr, &nlen, NULL, 0) == -1) {
+		GF_LOG(GF_LOG_ERROR, GF_LOG_CORE, ("[RTI] sysctl(%s...) failed: %s\n", name, strerror(errno)));
+		return -1;
+	}
+	if (nlen != len) {
+		GF_LOG(GF_LOG_ERROR, GF_LOG_CORE, ("[RTI] sysctl(%s...) expected %lu, got %lu\n",
+			name, (unsigned long)len, (unsigned long)nlen));
+		return -1;
+	}
+	return 0;
+}
+
+static int stathz = 128;
+
+Bool gf_sys_get_rti_os(u32 refresh_time_ms, GF_SystemRTInfo *rti, u32 flags)
+{
+	size_t length;
+	u32 entry_time;
+	struct kinfo_proc kinfo;
+	unsigned long result;
+	u32 u_k_time = 0, idle_time = 0;
+	u64 process_u_k_time = 0;
+	long cp_time[CPUSTATES];
+	struct clockinfo clockinfo;
+
+	entry_time = gf_sys_clock();
+	if (last_update_time && (entry_time - last_update_time < refresh_time_ms)) {
+		memcpy(rti, &the_rti, sizeof(GF_SystemRTInfo));
+		return 0;
+	}
+
+	int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, the_rti.pid };
+	length = sizeof(kinfo);
+
+	if (sysctl(mib, 4, &kinfo, &length, NULL, 0) == 0) {
+		process_u_k_time = (u64)(kinfo.ki_rusage.ru_utime.tv_usec + kinfo.ki_rusage.ru_stime.tv_usec) +
+			(u64)(kinfo.ki_rusage.ru_utime.tv_sec + kinfo.ki_rusage.ru_stime.tv_sec) * (u64)1000000;
+	}
+
+	if (GETSYSCTL("kern.cp_time", cp_time) == 0) {
+		u_k_time = cp_time[CP_USER] + cp_time[CP_NICE] + cp_time[CP_SYS] + cp_time[CP_INTR];
+		idle_time = cp_time[CP_IDLE];
+	}
+
+	the_rti.physical_memory = the_rti.physical_memory_avail = 0;
+	if (GETSYSCTL("hw.physmem", result) == 0) {
+		the_rti.physical_memory = result;
+	}
+
+	if (GETSYSCTL("hw.usermem", result) == 0) {
+		the_rti.physical_memory_avail = result;
+	}
+
+	the_rti.sampling_instant = last_update_time;
+
+	if (last_update_time) {
+		the_rti.sampling_period_duration = (entry_time - last_update_time);
+		the_rti.process_cpu_time_diff = (process_u_k_time - last_process_k_u_time) / 1000;
+
+		/*oops, we have no choice but to assume 100% cpu usage during this period*/
+		if (!u_k_time) {
+			the_rti.total_cpu_time_diff = the_rti.sampling_period_duration;
+			u_k_time = last_cpu_u_k_time + the_rti.sampling_period_duration;
+			the_rti.cpu_idle_time = 0;
+			the_rti.total_cpu_usage = 100;
+			if (!the_rti.process_cpu_time_diff) the_rti.process_cpu_time_diff = the_rti.total_cpu_time_diff;
+			the_rti.process_cpu_usage = (u32) ( 100 *  the_rti.process_cpu_time_diff / the_rti.sampling_period_duration);
+		} else {
+			u64 samp_sys_time, cpu_idle_time;
+			/*move to ms (kern.cp_time gives times in 1/stathz unit*/
+			the_rti.total_cpu_time_diff = (u_k_time - last_cpu_u_k_time) * 1000 / stathz;
+
+			/*we're not that accurate....*/
+			if (the_rti.total_cpu_time_diff > the_rti.sampling_period_duration)
+				the_rti.sampling_period_duration = the_rti.total_cpu_time_diff;
+
+			if (!idle_time) idle_time = (the_rti.sampling_period_duration - the_rti.total_cpu_time_diff) * stathz / 1000;
+			samp_sys_time = u_k_time - last_cpu_u_k_time;
+			cpu_idle_time = idle_time - last_cpu_idle_time;
+			the_rti.total_cpu_usage = (u32) ( 100 * samp_sys_time / (cpu_idle_time + samp_sys_time ) );
+			/*move to ms (kern.cp_time gives times in 1/stathz unit*/
+			the_rti.cpu_idle_time = cpu_idle_time * 1000 / stathz;
+			if (!the_rti.process_cpu_time_diff) the_rti.process_cpu_time_diff = the_rti.total_cpu_time_diff;
+			the_rti.process_cpu_usage = (u32) ( stathz * the_rti.process_cpu_time_diff / (cpu_idle_time + samp_sys_time) / 10 );
+		}
+	} else {
+		mem_at_startup = the_rti.physical_memory_avail;
+		if (GETSYSCTL("kern.clockrate", clockinfo) == 0) {
+			if (clockinfo.stathz > 0) {
+				stathz = clockinfo.stathz;
+			}
+		}
+	}
+	the_rti.process_memory = mem_at_startup - the_rti.physical_memory_avail;
+
+#ifdef GPAC_MEMORY_TRACKING
+	the_rti.gpac_memory = gpac_allocated_memory;
+#endif
+
+	last_process_k_u_time = process_u_k_time;
+	last_cpu_idle_time = idle_time;
+	last_cpu_u_k_time = u_k_time;
+	last_update_time = entry_time;
+	memcpy(rti, &the_rti, sizeof(GF_SystemRTInfo));
+	return 1;
+}
+
 //linux
 #else
 

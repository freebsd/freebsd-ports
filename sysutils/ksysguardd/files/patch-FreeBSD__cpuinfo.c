--- FreeBSD/cpuinfo.c	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/cpuinfo.c	2011-02-19 10:12:35.000000000 +0200
@@ -0,0 +1,655 @@
+/*
+    KSysGuard, the KDE System Guard
+
+	Copyright (c) 1999 Chris Schlaeger <cs@kde.org>
+	Copyright (c) 2010 David Naylor <naylor.b.david@gmail.com>
+
+    This program is free software; you can redistribute it and/or modify
+    it under the terms of the GNU General Public License as published by
+    the Free Software Foundation; either version 2 of the License, or
+    (at your option) any later version.
+
+    This program is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+    GNU General Public License for more details.
+
+    You should have received a copy of the GNU General Public License
+    along with this program; if not, write to the Free Software
+    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
+
+*/
+
+#include <sys/types.h>
+
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+
+#include <devstat.h>
+#include <fcntl.h>
+#include <nlist.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
+#include "cpuinfo.h"
+#include "Command.h"
+#include "ksysguardd.h"
+
+#define FREQ_LEVEL_BUFFER 256
+#define SYSCTL_ID_LEN 35
+
+static void get_mmfreq(int, int*, int*);
+
+static long percentages(int cnt, long *out, long *new, long *old, long *diffs);
+
+static long (*cp_time)[CPUSTATES] = NULL;
+static long (*cp_old)[CPUSTATES] = NULL;
+static long (*cp_diff)[CPUSTATES] = NULL;
+
+static int maxcpus = 1;
+static int cpus = 1;
+static int cores = 1;
+static int (*freq)[3] = NULL;
+static int *temp = NULL;
+
+static long (*cpu_states)[CPUSTATES] = NULL;
+
+void
+initCpuInfo(struct SensorModul* sm)
+{
+	size_t len;
+	int id;
+	char name[SYSCTL_ID_LEN];
+	int minfreq, maxfreq;
+
+	len = sizeof(cpus);
+	// XXX: this is a guess
+	sysctlbyname("kern.smp.active", &cpus, &len, NULL, 0);
+	// NOTE: cpus may be 0, which implies 1
+	cpus = cpus ? cpus : 1;
+
+	len = sizeof(cores);
+	sysctlbyname("kern.smp.cpus", &cores, &len, NULL, 0);
+
+	len = sizeof(maxcpus);
+	sysctlbyname("kern.smp.maxcpus", &maxcpus, &len, NULL, 0);
+
+	/* Core/process count */
+	registerMonitor("system/processors", "integer", printNumCpus, printNumCpusInfo, sm);
+	registerMonitor("system/cores", "integer", printNumCores, printNumCoresInfo, sm);
+
+	/*
+	 * CPU Loads
+	 */
+	if ((cp_time = malloc(sizeof(long) * CPUSTATES * (cores * 4 + 1))) == NULL) {
+		log_error("out of memory for cp_time");
+		return;
+	}
+	cp_old = &cp_time[cores];
+	cp_diff = &cp_old[cores];
+	cpu_states = &cp_diff[cores];
+
+	/* Total CPU load */
+	registerMonitor("cpu/system/user", "float", printCPUUser, printCPUUserInfo, sm);
+	registerMonitor("cpu/system/nice", "float", printCPUNice, printCPUNiceInfo, sm);
+	registerMonitor("cpu/system/sys", "float", printCPUSys, printCPUSysInfo, sm);
+	registerMonitor("cpu/system/TotalLoad", "float", printCPUTotalLoad, printCPUTotalLoadInfo, sm);
+	registerMonitor("cpu/system/intr", "float", printCPUIntr, printCPUIntrInfo, sm);
+	registerMonitor("cpu/system/idle", "float", printCPUIdle, printCPUIdleInfo, sm);
+
+	/* Monitor names changed from kde3 => kde4. Remain compatible with legacy requests when possible. */
+	registerLegacyMonitor("cpu/user", "float", printCPUUser, printCPUUserInfo, sm);
+	registerLegacyMonitor("cpu/nice", "float", printCPUNice, printCPUNiceInfo, sm);
+	registerLegacyMonitor("cpu/sys", "float", printCPUSys, printCPUSysInfo, sm);
+	registerLegacyMonitor("cpu/idle", "float", printCPUIdle, printCPUIdleInfo, sm);
+
+	for (id = 0; id < cores; ++id) {
+		snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/user", id);
+		registerMonitor(name, "float", printCPUxUser, printCPUxUserInfo, sm);
+		snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/nice", id);
+		registerMonitor(name, "float", printCPUxNice, printCPUxNiceInfo, sm);
+		snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/sys", id);
+		registerMonitor(name, "float", printCPUxSys, printCPUxSysInfo, sm);
+		snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/TotalLoad", id);
+		registerMonitor(name, "float", printCPUxTotalLoad, printCPUxTotalLoadInfo, sm);
+		snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/intr", id);
+		registerMonitor(name, "float", printCPUxIntr, printCPUxIntrInfo, sm);
+		snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/idle", id);
+		registerMonitor(name, "float", printCPUxIdle, printCPUxIdleInfo, sm);
+	}
+
+	/*
+	 * CPU frequencies
+	 */
+	if ((freq = malloc(sizeof(int) * 3 * (cores + 1))) == NULL) {
+		log_error("out of memory for freq");
+		return;
+	}
+
+	registerMonitor("cpu/system/AverageClock", "float", printCPUClock, printCPUClockInfo, sm);
+	for (id = 0; id < cores; ++id) {
+		len = sizeof(int);
+		snprintf(name, SYSCTL_ID_LEN, "dev.cpu.%d.freq", id);
+		if (!sysctlbyname(name, &freq[id][0], &len, NULL, 0)) {
+			get_mmfreq(id, &freq[id][1], &freq[id][2]);
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/clock", id);
+			registerMonitor(name, "integer", printCPUxClock, printCPUxClockInfo, sm);
+		} else {
+			freq[id][0] = -1;
+			freq[id][1] = 0;
+			freq[id][2] = 0;
+		}
+	}
+
+	minfreq = freq[0][1];
+	maxfreq = freq[0][2];
+	for (id = 1; id < cores; ++id)
+		if (freq[id][0] != -1) {
+			minfreq = minfreq > freq[id][1] ? freq[id][1] : minfreq;
+			maxfreq = maxfreq < freq[id][2] ? freq[id][2] : maxfreq;
+		}
+	freq[cores][1] = minfreq;
+	freq[cores][2] = maxfreq;
+
+	/*
+	 * CPU temperature
+	 */
+	if ((temp = malloc(sizeof(int) * (cores + 1))) == NULL) {
+		log_error("out of memory for temp");
+		return;
+	}
+	registerMonitor("cpu/system/AverageTemperature", "float", printCPUTemperature, printCPUTemperatureInfo, sm);
+	for (id = 0; id < cores; ++id) {
+		len = sizeof(int);
+		snprintf(name, SYSCTL_ID_LEN, "dev.cpu.%d.temperature", id);
+		if (!sysctlbyname(name, &temp[id], &len, NULL, 0)) {
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/temperature", id);
+			registerMonitor(name, "float", printCPUxTemperature, printCPUxTemperatureInfo, sm);
+		} else
+			temp[id] = -1;
+	}
+
+	updateCpuInfo();
+}
+
+void
+exitCpuInfo(void)
+{
+	int id;
+	char name[SYSCTL_ID_LEN];
+
+	removeMonitor("system/processors");
+	removeMonitor("system/cores");
+
+	if (cp_time != NULL) {
+		removeMonitor("cpu/system/user");
+		removeMonitor("cpu/system/nice");
+		removeMonitor("cpu/system/sys");
+		removeMonitor("cpu/system/TotalLoad");
+		removeMonitor("cpu/system/intr");
+		removeMonitor("cpu/system/idle");
+
+		/* These were registered as legacy monitors */
+		removeMonitor("cpu/user");
+		removeMonitor("cpu/nice");
+		removeMonitor("cpu/sys");
+		removeMonitor("cpu/idle");
+
+		for (id = 0; id < cores; ++id) {
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/user", id);
+			removeMonitor(name);
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/nice", id);
+			removeMonitor(name);
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/sys", id);
+			removeMonitor(name);
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/TotalLoad", id);
+			removeMonitor(name);
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/intr", id);
+			removeMonitor(name);
+			snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/idle", id);
+			removeMonitor(name);
+
+			if (freq != NULL && freq[id][0] != -1) {
+				snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/clock", id);
+				removeMonitor(name);
+			}
+			if (temp != NULL && temp[id] != -1) {
+				snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/temperature", id);
+				removeMonitor(name);
+			}
+		}
+
+		free(cp_time);
+		cp_time = NULL;
+	}
+
+	if (freq != NULL) {
+		removeMonitor("cpu/system/AverageClock");
+		for (id = 0; id < cores; ++id)
+			if (freq[id][0] != -1) {
+				snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/clock", id);
+				removeMonitor(name);
+			}
+		free(freq);
+		freq = NULL;
+	}
+
+	if (temp != NULL) {
+		removeMonitor("cpu/system/AverageTemperature");
+		for (id = 0; id < cores; ++id)
+			if (temp[id] != -1) {
+				snprintf(name, SYSCTL_ID_LEN, "cpu/cpu%d/temperature", id);
+				removeMonitor(name);
+			}
+		free(temp);
+		temp = NULL;
+	}
+
+}
+
+int
+updateCpuInfo(void)
+{
+	int sid, id, tot_freq = 0, tot_temp = 0, freq_count = 0, temp_count = 0;
+	char name[SYSCTL_ID_LEN];
+
+	if (cp_time == NULL || freq == NULL || temp == NULL)
+		return (0);
+
+        size_t len = sizeof(long) * CPUSTATES * cores;
+        sysctlbyname("kern.cp_times", cp_time, &len, NULL, 0);
+	for (sid = 0; sid < CPUSTATES; ++sid)
+		cpu_states[cores][sid] = 0;
+	for (id = 0; id < cores; ++id) {
+		percentages(CPUSTATES, cpu_states[id], cp_time[id], cp_old[id], cp_diff[id]);
+		for (sid = 0; sid < CPUSTATES; ++sid)
+			cpu_states[cores][sid] += cpu_states[id][sid];
+	}
+	for (id = 0; id < cores; ++id) {
+		if (freq[id][0] != -1) {
+			len = sizeof(int);
+			snprintf(name, SYSCTL_ID_LEN, "dev.cpu.%d.freq", id);
+			freq[id][0] = 0;
+			if (!sysctlbyname(name, &freq[id][0], &len, NULL, 0)) {
+				freq_count += 1;
+				tot_freq += freq[id][0];
+			}
+		}
+		if (temp[id] != -1) {
+			len = sizeof(int);
+			snprintf(name, SYSCTL_ID_LEN, "dev.cpu.%d.temperature", id);
+			temp[id] = 0.0;
+			if (!sysctlbyname(name, &temp[id], &len, NULL, 0)) {
+				temp_count += 1;
+				tot_temp += temp[id];
+			}
+		}
+	}
+	freq[cores][0] = freq_count == 0 ? 0 : tot_freq * 100 / freq_count;
+	temp[cores] = temp_count == 0 ? 0.0 : tot_temp * 100 / temp_count;
+
+	return (0);
+}
+
+void
+printCPUUser(const char* cmd)
+{
+	fprintf(CurrentClient, "%f\n", cpu_states[cores][CP_USER] / 10.0 / cores);
+}
+
+void
+printCPUUserInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU User Load\t0\t100\t%%\n");
+}
+
+void
+printCPUNice(const char* cmd)
+{
+	fprintf(CurrentClient, "%f\n", cpu_states[cores][CP_NICE] / 10.0 / cores);
+}
+
+void
+printCPUNiceInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU Nice Load\t0\t100\t%%\n");
+}
+
+void
+printCPUSys(const char* cmd)
+{
+	fprintf(CurrentClient, "%f\n", cpu_states[cores][CP_SYS] / 10.0 / cores);
+}
+
+void
+printCPUSysInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU System Load\t0\t100\t%%\n");
+}
+
+void
+printCPUTotalLoad(const char* cmd)
+{
+	fprintf(CurrentClient, "%f\n", (cpu_states[cores][CP_SYS] + cpu_states[cores][CP_USER] +
+	    cpu_states[cores][CP_NICE] + cpu_states[cores][CP_INTR]) / 10.0 / cores);
+}
+
+void
+printCPUTotalLoadInfo(const char* cmd)
+{
+        fprintf(CurrentClient, "CPU Total Load\t0\t100\t%%\n");
+}
+
+void
+printCPUIntr(const char* cmd)
+{
+        fprintf(CurrentClient, "%f\n", cpu_states[cores][CP_INTR] / 10.0 / cores);
+}
+
+void
+printCPUIntrInfo(const char* cmd)
+{
+        fprintf(CurrentClient, "CPU Interrupt Load\t0\t100\t%%\n");
+}
+
+void
+printCPUIdle(const char* cmd)
+{
+	fprintf(CurrentClient, "%f\n", cpu_states[cores][CP_IDLE] / 10.0 / cores);
+}
+
+void
+printCPUIdleInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU Idle Load\t0\t100\t%%\n");
+}
+
+void
+printCPUxUser(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%0.1f\n", cpu_states[id][CP_USER] / 10.0);
+}
+
+void
+printCPUxUserInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d User Load\t0\t100\t%%\n", id + 1);
+}
+
+void
+printCPUxNice(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%0.1f\n", cpu_states[id][CP_NICE] / 10.0);
+}
+
+void
+printCPUxNiceInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d Nice Load\t0\t100\t%%\n", id + 1);
+}
+
+void
+printCPUxSys(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%0.1f\n", cpu_states[id][CP_SYS] / 10.0);
+}
+
+void
+printCPUxSysInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d System Load\t0\t100\t%%\n", id + 1);
+}
+
+void
+printCPUxTotalLoad(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%f\n", (cpu_states[id][CP_SYS] + cpu_states[id][CP_USER] +
+	    cpu_states[id][CP_NICE] + cpu_states[id][CP_INTR]) / 10.0);
+}
+
+void
+printCPUxTotalLoadInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d Total Load\t0\t100\t%%\n", id + 1);
+}
+
+void
+printCPUxIntr(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+        fprintf(CurrentClient, "%0.1f\n", cpu_states[id][CP_INTR] / 10.0);
+}
+
+void
+printCPUxIntrInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d Interrupt Load\t0\t100\t%%\n", id + 1);
+}
+
+void
+printCPUxIdle(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%0.1f\n", cpu_states[id][CP_IDLE] / 10.0);
+}
+
+void
+printCPUxIdleInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d Idle Load\t0\t100\t%%\n", id + 1);
+}
+
+void printCPUxClock(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%d\n", freq[id][0]);
+}
+
+void printCPUxClockInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d Clock Frequency\t%d\t%d\tMHz\n", id + 1, 
+		freq[id][1], freq[id][2]);
+}
+
+void printCPUClock(const char* cmd)
+{
+	fprintf(CurrentClient, "%f\n", freq[cores][0] / 100.0);
+}
+
+void printCPUClockInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU Clock Frequency\t%d\t%d\tMHz\n", freq[cores][1], freq[cores][2]);
+}
+
+void printCPUxTemperature(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "%0.1f\n", (temp[id] - 2732) / 10.0);
+}
+
+void printCPUxTemperatureInfo(const char* cmd)
+{
+	int id;
+
+	sscanf(cmd + 7, "%d", &id);
+	fprintf(CurrentClient, "CPU%d Temperature\t0\t0\tC\n", id + 1);
+}
+
+void printCPUTemperature(const char* cmd)
+{
+	fprintf(CurrentClient, "%0.3f\n", (temp[cores] - 273200) / 1000.0);
+}
+
+void printCPUTemperatureInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "CPU Temperature\t0\t0\tC\n");
+}
+
+void printNumCpus(const char* cmd)
+{
+	fprintf(CurrentClient, "%d\n", cpus);
+}
+
+void printNumCpusInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Number of physical CPUs\t0\t%d\t\n", maxcpus);
+}
+
+void printNumCores(const char* cmd)
+{
+	fprintf(CurrentClient, "%d\n", cores);
+}
+
+void printNumCoresInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Total number of processor cores\t0\t%d\t\n", maxcpus);
+}
+
+void get_mmfreq(int id, int* minfreq, int* maxfreq)
+{
+	char buf[FREQ_LEVEL_BUFFER];
+	char mid[SYSCTL_ID_LEN];
+	size_t len = FREQ_LEVEL_BUFFER;
+	
+	*minfreq = 0;
+	*maxfreq = 0;
+
+	snprintf(mid, sizeof(mid), "dev.cpu.%d.freq_levels", id);
+	if (!sysctlbyname(mid, buf, &len, NULL, 0))
+	{
+		char *start = buf;
+		char *end;
+
+		/*
+		 * The string is ([[freq]]/[[num]] )*([[freq]]/[[num]] ), so
+		 * for each frequency we get we must also skip over another
+		 * set of numbers
+		 */
+		while (1)
+		{
+			// Get the first number
+			int number = strtol(start, &end, 10);
+			if (start == end)
+				break;
+			if (!*maxfreq)
+				*maxfreq = number;
+			else
+				*minfreq = number;
+			if (!*end)
+				break;
+			start = end + 1;
+			
+			// Skip over the next number
+			strtol(start, &end, 10);
+			if (start == end || !*end)
+				break;
+			start = end + 1;
+		}
+	}
+}
+
+/* The part ripped from top... */
+/*
+ *  Top users/processes display for Unix
+ *  Version 3
+ *
+ *  This program may be freely redistributed,
+ *  but this entire comment MUST remain intact.
+ *
+ *  Copyright (c) 1984, 1989, William LeFebvre, Rice University
+ *  Copyright (c) 1989, 1990, 1992, William LeFebvre, Northwestern University
+ */
+
+/*
+ *  percentages(cnt, out, new, old, diffs) - calculate percentage change
+ *	between array "old" and "new", putting the percentages i "out".
+ *	"cnt" is size of each array and "diffs" is used for scratch space.
+ *	The array "old" is updated on each call.
+ *	The routine assumes modulo arithmetic.  This function is especially
+ *	useful on BSD mchines for calculating cpu state percentages.
+ */
+long percentages(int cnt, long *out, long *new, long *old, long *diffs)
+{
+    int i;
+    long change;
+    long total_change;
+    long *dp;
+    long half_total;
+
+    /* initialization */
+    total_change = 0;
+    dp = diffs;
+
+    /* calculate changes for each state and the overall change */
+    for (i = 0; i < cnt; i++)
+    {
+	if ((change = *new - *old) < 0)
+	{
+	    /* this only happens when the counter wraps */
+	    change = (int)
+		((unsigned long)*new-(unsigned long)*old);
+	}
+	total_change += (*dp++ = change);
+	*old++ = *new++;
+    }
+
+    /* avoid divide by zero potential */
+    if (total_change == 0)
+    {
+	total_change = 1;
+    }
+
+    /* calculate percentages based on overall change, rounding up */
+    half_total = total_change / 2l;
+
+    /* Do not divide by 0. Causes Floating point exception */
+    for (i = 0; i < cnt; i++)
+    {
+	*out++ = (int)((*diffs++ * 1000 + half_total) / total_change);
+    }
+
+    /* return the total in case the caller wants to use it */
+    return(total_change);
+}

--- FreeBSD/stat.c	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/stat.c	2011-02-10 15:37:53.000000000 +0200
@@ -0,0 +1,379 @@
+/*
+	KSysGuard, the KDE System Guard
+	
+	Copyright (c) 2011 David Naylor <naylor.b.david@gmail.com>
+	
+	This program is free software; you can redistribute it and/or
+	modify it under the terms of version 2 of the GNU General Public
+	License as published by the Free Software Foundation.
+	
+	This program is distributed in the hope that it will be useful,
+	but WITHOUT ANY WARRANTY; without even the implied warranty of
+	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+	GNU General Public License for more details.
+	
+	You should have received a copy of the GNU General Public License
+	along with this program; if not, write to the Free Software
+	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
+*/
+
+/*
+ * TODO
+ * - stray irq
+ * - cpu*:timer
+ */
+
+#include "stat.h"
+
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
+#include "Command.h"
+
+#define IRQ_NAME 32
+
+char *sysctl_dynread(const char *);
+
+static u_int context, context_last = 0;
+static u_int trap, trap_last = 0;
+static u_int syscall, syscall_last = 0;
+static u_int hardint, hardint_last = 0;
+static u_int softint, softint_last = 0;
+
+static u_int intrcnt, nintr = 0, msi_offset = 0;
+static char **intrname = NULL, *intrnamebuf;
+static long *intr = NULL, *intr_last, *intr_current;
+static int *intr_map = NULL;
+
+void initStat(struct SensorModul *sm) {
+	int irq, irq_len = 0, msi_len = 0;
+	size_t len = 0;
+	char name[IRQ_NAME], *cp;
+
+	sysctlbyname("hw.intrcnt", NULL, &len, NULL, 0);
+	intrcnt = len / sizeof(unsigned long);
+
+	if ((intr = malloc(intrcnt * 3 * sizeof (long))) == NULL) {
+		log_error("out of memory for intr");
+		return;
+	}
+	intr_last = &intr[intrcnt];
+	intr_current = &intr_last[intrcnt];
+
+	if ((intrname = malloc(intrcnt * sizeof(char *))) == NULL) {
+		log_error("out of memory for intrname");
+		return;
+	}
+
+	if ((intrnamebuf = sysctl_dynread("hw.intrnames")) == NULL) {
+		log_error("out of memory for intrnamebuf");
+		return;
+	}
+	for (cp = intrnamebuf, irq = 0; irq < intrcnt; ++irq) {
+		char *nextcp;
+		for (nextcp = cp; *nextcp != '\0'; ++nextcp);
+		if (strncmp(cp, "irq", 3) == 0) {
+			long irq2;
+			sscanf(cp + 3, "%ld", &irq2);
+			if (irq2 > 255)
+				++msi_len;
+			else
+				if (irq_len < irq2)
+					irq_len = irq2;
+		} else if (nextcp == cp)
+			intrcnt = irq;
+		cp = nextcp + 1;
+	}
+	if (msi_len)
+		msi_offset = 255 - irq_len;
+	nintr  = irq_len + msi_len + 1;
+	if ((intr_map = malloc(nintr * sizeof(int))) == NULL) {
+		log_error("out of memory for intr_map");
+		return;
+	}
+
+	for (irq = 0; irq < nintr; ++irq)
+		intr_map[irq] = -1;
+	for (cp = intrnamebuf, irq = 0; irq < intrcnt; ++irq) {
+		char *nextcp;
+		for (nextcp = cp; *nextcp != '\0'; ++nextcp)
+			if (*nextcp == ' ' && (*(nextcp + 1) == ' ' || *(nextcp + 1) == '\0'))
+				*nextcp = '\0';
+		intrname[irq] = cp;
+		if (strncmp(cp, "irq", 3) == 0) {
+			long irq2;
+			sscanf(cp + 3, "%ld", &irq2);
+			if (irq2 < 256)
+				intr_map[irq2] = irq;
+			else
+				intr_map[irq2 - msi_offset] = irq;
+			strncpy(cp, "IRQ", 3);
+			for(cp = cp + 4; *cp != ':'; ++cp);
+			for(; ; ++cp)
+				if (*cp == '\0')
+					break;
+				else if (*cp == ':')
+					if (*(cp + 1) == '\0')
+						*cp = '\0';
+					else
+						*cp = '(';
+				else if (*(cp + 1) == '\0')
+					*cp = ')';
+				else
+					*cp = *(cp + 1);
+		} else if (nextcp == cp)
+			intrcnt = irq;
+		cp = nextcp + 1;
+	}
+	
+	registerMonitor("cpu/interrupts/hardint", "integer", printHardInt, printHardIntInfo, sm);
+	registerMonitor("cpu/interrupts/softint", "integer", printSoftInt, printSoftIntInfo, sm);
+	registerLegacyMonitor("cpu/interrupts/int00", "integer", printHardInt, printHardIntInfo, sm);
+
+	for (irq = 0; irq < nintr; ++irq) {
+		if (intr_map[irq] == -1)
+			continue;
+		if (irq > 255 - msi_offset)
+			snprintf(name, IRQ_NAME, "cpu/interrupts/int%03d", irq + msi_offset);
+		else
+			snprintf(name, IRQ_NAME, "cpu/interrupts/int%02d", irq + 1);
+		registerMonitor(name, "integer", printInterruptx, printInterruptxInfo, sm);
+	}
+
+	registerMonitor("cpu/context", "integer", printContext, printContextInfo, sm);
+	registerMonitor("cpu/trap", "integer", printTrap, printTrapInfo, sm);
+	registerMonitor("cpu/syscall", "integer", printSyscall, printSyscallInfo, sm);
+
+	updateStat();
+}
+	
+void exitStat(void) {
+	int irq;
+	char name[IRQ_NAME];
+	
+	if (intr != NULL) {
+		free(intr);
+		intr = NULL;
+		intr_current = NULL;
+		intr_last = NULL;
+	}
+
+	if (intrname != NULL) {
+		free(intrname);
+		intrname = NULL;
+	}
+
+	if (intrnamebuf != NULL) {
+		if (intr_map != NULL) {
+			removeMonitor("cpu/interrupts/hardint");
+			removeMonitor("cpu/interrupts/softint");
+			removeMonitor("cpu/interrupts/int00");
+
+			for (irq = 0; irq < nintr; ++irq) {
+				if (intr_map[irq] == -1)
+					continue;
+					if (irq > 255 - msi_offset)
+						snprintf(name, IRQ_NAME, "cpu/interrupts/int%03d", irq + msi_offset);
+					else
+						snprintf(name, IRQ_NAME, "cpu/interrupts/int%02d", irq + 1);
+				removeMonitor(name);
+			}
+
+			removeMonitor("cpu/context");
+			removeMonitor("cpu/trap");
+			removeMonitor("cpu/syscall");
+
+			free(intr_map);
+			intr_map = NULL;
+		}
+
+		free(intrnamebuf);
+		intrnamebuf = NULL;
+	}
+}
+
+int updateStat(void) {
+	int irq;
+	size_t len;
+	unsigned int current;
+	long *swap;
+
+#define GETSYSCTL(mib, var)						\
+	len = sizeof(var);						\
+	sysctlbyname(mib, &var, &len, NULL, 0);
+#define GETDIFFSYSCTL(mib, var)						\
+	GETSYSCTL(mib, current);					\
+	var = current - var##_last;					\
+	var##_last = current;
+
+	GETDIFFSYSCTL("vm.stats.sys.v_swtch", context);
+	GETDIFFSYSCTL("vm.stats.sys.v_trap", trap);
+	GETDIFFSYSCTL("vm.stats.sys.v_syscall", syscall);
+	GETDIFFSYSCTL("vm.stats.sys.v_intr", hardint);
+	GETDIFFSYSCTL("vm.stats.sys.v_soft", softint);
+
+	len = sizeof(long) * intrcnt;
+	sysctlbyname("hw.intrcnt", intr_current, &len, NULL, 0);
+	for (irq = 0; irq < nintr; ++irq)
+		if (intr_map[irq] != -1)
+			intr[intr_map[irq]] = intr_current[intr_map[irq]] - intr_last[intr_map[irq]];
+	swap = intr_current;
+	intr_current = intr_last;
+	intr_last = swap;
+
+	return (0);
+
+#undef GETDIFFSYSCTL
+#undef GETSYSCTL
+}
+
+void printHardInt(const char *cmd) {
+	fprintf(CurrentClient, "%d\n", hardint);
+}
+
+void printHardIntInfo(const char *cmd) {
+	fprintf(CurrentClient, "Hardware Interrupts\t0\t0\t1/s\n");
+}
+
+void printSoftInt(const char *cmd) {
+	fprintf(CurrentClient, "%d\n", softint);
+}
+
+void printSoftIntInfo(const char *cmd) {
+	fprintf(CurrentClient, "Software Interrupts\t0\t0\t1/s\n");
+}
+
+void printInterruptx(const char *cmd) {
+	int irq;
+
+	sscanf(cmd + 18, "%d", &irq);
+	if (irq > 255 - msi_offset)
+		irq -= msi_offset - 1;
+	fprintf(CurrentClient, "%ld\n", intr[intr_map[irq - 1]]);
+}
+
+void printInterruptxInfo(const char *cmd) {
+	int irq;
+
+	sscanf(cmd + 18, "%d", &irq);
+	if (irq > 255 - msi_offset)
+		irq -= msi_offset - 1;
+	fprintf(CurrentClient, "%s\t0\t0\t1/s\n", intrname[intr_map[irq - 1]]);
+}
+
+void printContext(const char *cmd) {
+	fprintf(CurrentClient, "%u\n", context);
+}
+
+void printContextInfo(const char *cmd) {
+	fprintf(CurrentClient, "Context switches\t0\t0\t1/s\n");
+}
+
+void printTrap(const char *cmd) {
+	fprintf(CurrentClient, "%u\n", trap);
+}
+
+void printTrapInfo(const char *cmd) {
+	fprintf(CurrentClient, "Traps\t0\t0\t1/s\n");
+}
+
+void printSyscall(const char *cmd) {
+	fprintf(CurrentClient, "%u\n", syscall);
+}
+
+void printSyscallInfo(const char *cmd) {
+	fprintf(CurrentClient, "System Calls\t0\t0\t1/s\n");
+}
+
+/*
+ * Taken from http://cvsweb.freebsd.org/src/usr.bin/systat/fetch.c
+ */
+/*-
+ * Copyright (c) 1983, 1989, 1992, 1993
+ *	The Regents of the University of California.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 4. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+/*
+ * Read sysctl data with variable size. Try some times (with increasing 
+ * buffers), fail if still too small.
+ * This is needed sysctls with possibly raplidly increasing data sizes,
+ * but imposes little overhead in the case of constant sizes.
+ * Returns NULL on error, or a pointer to freshly malloc()'ed memory that holds
+ * the requested data.
+ * If szp is not NULL, the size of the returned data will be written into *szp.
+ */
+
+/* Some defines: Number of tries. */
+#define SD_NTRIES  10
+/* Percent of over-allocation (initial) */
+#define SD_MARGIN  10 
+/* 
+ * Factor for over-allocation in percent (the margin is increased by this on
+ * any failed try).
+ */
+#define SD_FACTOR  50
+/* Maximum supported MIB depth */
+#define SD_MAXMIB  16
+char *
+sysctl_dynread(const char *n)
+{
+	char   *rv = NULL;
+	int    mib[SD_MAXMIB];
+	size_t mibsz = SD_MAXMIB;
+	size_t mrg = SD_MARGIN;
+	size_t sz;
+	int i;
+
+	/* cache the MIB */
+	if (sysctlnametomib(n, mib, &mibsz) == -1) {
+		return NULL;
+	}
+	for (i = 0; i < SD_NTRIES; i++) {
+		/* get needed buffer size */
+		if (sysctl(mib, mibsz, NULL, &sz, NULL, 0) == -1)
+			break;
+		sz += sz * mrg / 100;
+		if ((rv = (char *)malloc(sz)) == NULL)
+			return NULL;
+		if (sysctl(mib, mibsz, rv, &sz, NULL, 0) == -1) {
+			free(rv);
+			rv = NULL;
+			if (errno == ENOMEM) {
+				mrg += mrg * SD_FACTOR / 100;
+			} else
+				break;
+		} else {
+			/* success */
+			break;
+		}
+	}
+
+	return rv;
+}

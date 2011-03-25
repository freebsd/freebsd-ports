--- FreeBSD/Memory.c	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/Memory.c	2011-01-30 11:18:45.000000000 +0200
@@ -3,6 +3,7 @@
 
 	Copyright (c) 1999-2000 Hans Petter Bieker <bieker@kde.org>
 	Copyright (c) 1999 Chris Schlaeger <cs@kde.org>
+	Copyright (c) 2010 David Naylor <naylor.b.david@gmail.com>
 
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
@@ -21,33 +22,39 @@
 */
 
 #include <sys/types.h>
-#include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/vmmeter.h>
-
-#include <vm/vm_param.h>
 
 #include <fcntl.h>
 #include <kvm.h>
 #include <limits.h>
 #include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
 #include <unistd.h>
 
 #include "Command.h"
 #include "Memory.h"
 #include "ksysguardd.h"
 
-static size_t Total = 0;
-static size_t MFree = 0;
-static size_t Used = 0;
-static size_t Buffers = 0;
-static size_t Cached = 0;
-static size_t Application = 0;
-static size_t STotal = 0;
-static size_t SFree = 0;
-static size_t SUsed = 0;
+#define MEM_ACTIVE 0
+#define MEM_INACTIVE 1
+#define MEM_WIRED 2
+#define MEM_CACHED 3
+#define MEM_BUFFERED 4
+#define MEM_FREE 5
+#define MEM_TOTAL 6
+
+static size_t memory_stats[7];
+
+#define SWAP_IN 0
+#define SWAP_OUT 1
+#define SWAP_USED 2
+#define SWAP_FREE 3
+#define SWAP_TOTAL 4
+
+static size_t swap_stats[5];
+static size_t swap_old[2];
+
+static int pagesize;
+
 static kvm_t *kd;
 
 void
@@ -56,24 +63,57 @@
 	char *nlistf = NULL;
 	char *memf = NULL;
 	char buf[_POSIX2_LINE_MAX];
-	
+
+	pagesize = getpagesize();
+
 	if ((kd = kvm_openfiles(nlistf, memf, NULL, O_RDONLY, buf)) == NULL) {
 		log_error("kvm_openfiles()");
 		return;
 	}
 
-        registerMonitor("mem/physical/free", "integer", printMFree, printMFreeInfo, sm);
-	registerMonitor("mem/physical/used", "integer", printUsed, printUsedInfo, sm);
-	registerMonitor("mem/physical/buf", "integer", printBuffers, printBuffersInfo, sm);
-	registerMonitor("mem/physical/cached", "integer", printCached, printCachedInfo, sm);
-	registerMonitor("mem/physical/application", "integer", printApplication, printApplicationInfo, sm);
+	registerMonitor("mem/physical/active", "integer", printMActive, printMActiveInfo, sm);
+	registerMonitor("mem/physical/inactive", "integer", printMInactive, printMInactiveInfo, sm);
+	registerMonitor("mem/physical/application", "integer", printMApplication, printMApplicationInfo, sm);
+	registerMonitor("mem/physical/wired", "integer", printMWired, printMWiredInfo, sm);
+	registerMonitor("mem/physical/cached", "integer", printMCached, printMCachedInfo, sm);
+	registerMonitor("mem/physical/buf", "integer", printMBuffers, printMBuffersInfo, sm);
+	registerMonitor("mem/physical/free", "integer", printMFree, printMFreeInfo, sm);
+	registerMonitor("mem/physical/used", "integer", printMUsed, printMUsedInfo, sm);
+
 	registerMonitor("mem/swap/free", "integer", printSwapFree, printSwapFreeInfo, sm);
 	registerMonitor("mem/swap/used", "integer", printSwapUsed, printSwapUsedInfo, sm);
+	registerMonitor("mem/swap/pageIn", "integer", printSwapIn, printSwapInInfo, sm);
+	registerMonitor("mem/swap/pageOut", "integer", printSwapOut, printSwapOutInfo, sm);
+
+	registerLegacyMonitor("cpu/pageIn", "float", printSwapIn, printSwapInInfo, sm);
+	registerLegacyMonitor("cpu/pageOut", "float", printSwapOut, printSwapOutInfo, sm);
+
+	swap_old[SWAP_IN] = -1;
+	swap_old[SWAP_OUT] = -1;
+
+	updateMemory();
 }
 
 void
 exitMemory(void)
 {
+	removeMonitor("mem/physical/active");
+	removeMonitor("mem/physical/inactive");
+	removeMonitor("mem/physical/application");
+	removeMonitor("mem/physical/wired");
+	removeMonitor("mem/physical/cached");
+	removeMonitor("mem/physical/buf");
+	removeMonitor("mem/physical/free");
+	removeMonitor("mem/physical/used");
+
+	removeMonitor("mem/swap/free");
+	removeMonitor("mem/swap/used");
+	removeMonitor("mem/swap/pageIn");
+	removeMonitor("mem/swap/pageOut");
+
+	removeMonitor("cpu/pageIn");
+	removeMonitor("cpu/pageOut");
+
 	kvm_close(kd);
 }
 
@@ -81,129 +121,212 @@
 updateMemory(void)
 {
 	size_t len;
-	FILE *file;
-	char buf[256];
-	struct kvm_swap kswap[16];
-	int i, swap_count, hlen, pagesize = getpagesize();
-	long blocksize;
-
-        len = sizeof (Total);
-        sysctlbyname("hw.physmem", &Total, &len, NULL, 0);
-        Total /= 1024;
-
-	/* Borrowed from pstat */ 
-	swap_count = kvm_getswapinfo(kd, kswap, 16, SWIF_DEV_PREFIX);
-	getbsize(&hlen, &blocksize);
-
-#define CONVERT(v) ((int)((quad_t)(v) * pagesize / blocksize))
-
-	if (swap_count > 0) {
-		STotal = CONVERT(kswap[0].ksw_total);
-		SUsed = CONVERT(kswap[0].ksw_used);
-		SFree = CONVERT(kswap[0].ksw_total - kswap[0].ksw_used);
+	int swapin, swapout;
+
+#define CONVERT(v)	((quad_t)(v) * pagesize / 1024)
+
+#define GETSYSCTL(mib, var)						\
+	len = sizeof(var);						\
+	sysctlbyname(mib, &var, &len, NULL, 0);
+
+#define GETPAGESYSCTL(mib, var)						\
+	GETSYSCTL(mib, var)						\
+	var = CONVERT(var);
+
+#define GETMEMSYSCTL(mib, var)						\
+	GETSYSCTL(mib, var)						\
+	var /= 1024;
+
+	/*
+	 * Memory
+	 */
+	GETPAGESYSCTL("vm.stats.vm.v_active_count", memory_stats[MEM_ACTIVE])
+	GETPAGESYSCTL("vm.stats.vm.v_inactive_count", memory_stats[MEM_INACTIVE])
+	GETPAGESYSCTL("vm.stats.vm.v_wire_count", memory_stats[MEM_WIRED])
+	GETPAGESYSCTL("vm.stats.vm.v_cache_count", memory_stats[MEM_CACHED])
+	GETPAGESYSCTL("vm.stats.vm.v_free_count", memory_stats[MEM_FREE])
+	GETMEMSYSCTL("vfs.bufspace", memory_stats[MEM_BUFFERED])
+	GETMEMSYSCTL("hw.physmem", memory_stats[MEM_TOTAL])
+
+	/*
+	 * Swap
+	 */
+	GETSYSCTL("vm.stats.vm.v_swappgsin", swapin);
+	GETSYSCTL("vm.stats.vm.v_swappgsout", swapout);
+	
+	if (swap_old[SWAP_IN] < 0) {
+		swap_stats[SWAP_IN] = 0;
+		swap_stats[SWAP_OUT] = 0;
+	} else {
+		swap_stats[SWAP_IN] = CONVERT(swapin - swap_old[SWAP_IN]);
+		swap_stats[SWAP_OUT] = CONVERT(swapout - swap_old[SWAP_OUT]);
 	}
 
-        len = sizeof (Buffers);
-        if ((sysctlbyname("vfs.bufspace", &Buffers, &len, NULL, 0) == -1) || !len)
-                Buffers = 0; /* Doesn't work under FreeBSD v2.2.x */
-        Buffers /= 1024;
-
-        len = sizeof (Cached);
-        if ((sysctlbyname("vm.stats.vm.v_cache_count", &Cached, &len, NULL, 0) == -1) || !len)
-                Cached = 0; /* Doesn't work under FreeBSD v2.2.x */
-        Cached *= pagesize / 1024;
-
-	len = sizeof (MFree);
-	if ((sysctlbyname("vm.stats.vm.v_free_count", &MFree, &len, NULL, 0) == -1) || !len)
-		MFree = 0; /* Doesn't work under FreeBSD v2.2.x */
-	MFree *= pagesize / 1024;
+	/* call CPU heavy swapmode() only for changes */
+	if (swap_stats[SWAP_IN] > 0 || swap_stats[SWAP_OUT] > 0 || swap_old[SWAP_IN] < 0) {
+		struct kvm_swap swapary;
+		if (kvm_getswapinfo(kd, &swapary, 1, 0) < 0 || swapary.ksw_total == 0) {
+			int i;
+			for (i = 0; i < (sizeof(swap_stats) / sizeof(swap_stats[0])); ++i)
+				swap_stats[i] = 0;
+		} else {
+			swap_stats[SWAP_TOTAL] = CONVERT(swapary.ksw_total);
+			swap_stats[SWAP_USED] = CONVERT(swapary.ksw_used);
+			swap_stats[SWAP_FREE] = CONVERT(swapary.ksw_total - swapary.ksw_used);
+		}
+	}
 
-	Used = Total - MFree;
-	Application = Used - Buffers - Cached;
+	swap_old[SWAP_IN] = swapin;
+	swap_old[SWAP_OUT] = swapout;
 
 	return 0;
+
+#undef CONVERT
+#undef GETSYSCTL
+#undef GETPAGESYSCTL
+#undef GETMEMSYSCTL
 }
 
 void
-printMFree(const char* cmd)
+printMActive(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", MFree);
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_ACTIVE]);
 }
 
 void
-printMFreeInfo(const char* cmd)
+printMActiveInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Active Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
+}
+
+void
+printMInactive(const char* cmd)
+{
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_INACTIVE]);
+}
+
+void
+printMInactiveInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Inactive Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
+}
+
+void
+printMApplication(const char* cmd)
 {
-	fprintf(CurrentClient, "Free Memory\t0\t%d\tKB\n", Total);
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_ACTIVE] + memory_stats[MEM_INACTIVE]);
 }
 
 void
-printUsed(const char* cmd)
+printMApplicationInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Application (Active and Inactive) Memory\t0\t%ld\tKB\n", memory_stats[MEM_TOTAL]);
+}
+
+void 
+printMWired(const char* cmd)
+{
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_WIRED]);
+}
+
+void 
+printMWiredInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", Used);
+	fprintf(CurrentClient, "Wired Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
 }
 
 void
-printUsedInfo(const char* cmd)
+printMCached(const char* cmd)
 {
-	fprintf(CurrentClient, "Used Memory\t0\t%d\tKB\n", Total);
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_CACHED]);
 }
 
 void
-printBuffers(const char* cmd)
+printMCachedInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", Buffers);
+	fprintf(CurrentClient, "Cached Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
 }
 
 void
-printBuffersInfo(const char* cmd)
+printMBuffers(const char* cmd)
 {
-	fprintf(CurrentClient, "Buffer Memory\t0\t%d\tKB\n", Total);
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_BUFFERED]);
 }
 
 void
-printCached(const char* cmd)
+printMBuffersInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", Cached);
+	fprintf(CurrentClient, "Buffer Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
 }
 
 void
-printCachedInfo(const char* cmd)
+printMFree(const char* cmd)
 {
-	fprintf(CurrentClient, "Cached Memory\t0\t%d\tKB\n", Total);
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_FREE]);
 }
 
 void
-printApplication(const char* cmd)
+printMFreeInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", Application);
+	fprintf(CurrentClient, "Free Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
 }
 
 void
-printApplicationInfo(const char* cmd)
+printMUsed(const char* cmd)
 {
-	fprintf(CurrentClient, "Application Memory\t0\t%ld\tKB\n", Total);
+	fprintf(CurrentClient, "%lu\n", memory_stats[MEM_TOTAL] - memory_stats[MEM_FREE]);
+}
+
+void
+printMUsedInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Used Memory\t0\t%lu\tKB\n", memory_stats[MEM_TOTAL]);
 }
 
 void
 printSwapUsed(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", SUsed);
+	fprintf(CurrentClient, "%lu\n", swap_stats[SWAP_USED]);
 }
 
 void
 printSwapUsedInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "Used Swap Memory\t0\t%d\tKB\n", STotal);
+	fprintf(CurrentClient, "Used Swap Memory\t0\t%lu\tKB\n", swap_stats[SWAP_TOTAL]);
 }
 
 void
 printSwapFree(const char* cmd)
 {
-	fprintf(CurrentClient, "%d\n", SFree);
+	fprintf(CurrentClient, "%lu\n", swap_stats[SWAP_FREE]);
 }
 
 void
 printSwapFreeInfo(const char* cmd)
 {
-	fprintf(CurrentClient, "Free Swap Memory\t0\t%d\tKB\n", STotal);
+	fprintf(CurrentClient, "Free Swap Memory\t0\t%lu\tKB\n", swap_stats[SWAP_TOTAL]);
+}
+
+void
+printSwapIn(const char* cmd)
+{
+	fprintf(CurrentClient, "%lu\n", swap_stats[SWAP_IN]);
+}
+
+void
+printSwapInInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Swapped In Memory\t0\t0\tKB/s\n");
+}
+
+void
+printSwapOut(const char* cmd)
+{
+	fprintf(CurrentClient, "%lu\n", swap_stats[SWAP_OUT]);
+}
+
+void
+printSwapOutInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Swapped Out Memory\t0\t0\tKB/s\n");
 }

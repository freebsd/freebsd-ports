--- p4.c.orig	2016-10-10 22:08:11 UTC
+++ p4.c
@@ -176,8 +176,10 @@ static int decode_mca(u64 status, u64 mi
 		levelnum = mca & 3;
 		level = get_LL_str(levelnum);
 		Wprintf("%s Generic cache hierarchy error\n", level);
+#ifdef __Linux__
 		if (track == 2)
 			run_yellow_trigger(cpu, -1, levelnum, "unknown", level, socket);
+#endif
 	} else if (test_prefix(4, mca)) {
 		unsigned levelnum, typenum;
 		char *level, *type;
@@ -186,8 +188,10 @@ static int decode_mca(u64 status, u64 mi
 		levelnum = (mca & TLB_LL_MASK) >> TLB_LL_SHIFT;
 		level = get_LL_str(levelnum);
 		Wprintf("%s TLB %s Error\n", type, level);
+#ifdef __Linux__
 		if (track == 2)
 			run_yellow_trigger(cpu, typenum, levelnum, type, level, socket);
+#endif
 	} else if (test_prefix(8, mca)) {
 		unsigned typenum = (mca & CACHE_TT_MASK) >> CACHE_TT_SHIFT;
 		unsigned levelnum = (mca & CACHE_LL_MASK) >> CACHE_LL_SHIFT;
@@ -196,8 +200,10 @@ static int decode_mca(u64 status, u64 mi
 		Wprintf("%s CACHE %s %s Error\n", type, level,
 				get_RRRR_str((mca & CACHE_RRRR_MASK) >> 
 					      CACHE_RRRR_SHIFT));
+#ifdef __Linux__
 		if (track == 2)
 			run_yellow_trigger(cpu, typenum, levelnum, type, level,socket);
+#endif
 	} else if (test_prefix(10, mca)) {
 		if (mca == 0x400)
 			Wprintf("Internal Timer error\n");
@@ -216,7 +222,9 @@ static int decode_mca(u64 status, u64 mi
 
 		Wprintf("BUS error: %d %d %s %s %s %s %s\n", socket, cpu,
 			level, pp, rrrr, ii, timeout);
+#ifdef __Linux__
 		run_bus_trigger(socket, cpu, level, pp, rrrr, ii, timeout);
+#endif
 		/* IO MCA - reported as bus/interconnect with specific PP,T,RRRR,II,LL values
 		 * and MISCV set. MISC register points to root port that reported the error
 		 * need to cross check with AER logs for more details.
@@ -232,7 +240,9 @@ static int decode_mca(u64 status, u64 mi
 			fn = EXTRACT(misc, 16, 18);
 			Wprintf("IO MCA reported by root port %x:%02x:%02x.%x\n",
 				seg, bus, dev, fn);
+#ifdef __Linux__
 			run_iomca_trigger(socket, cpu, seg, bus, dev, fn);
+#endif
 		}
 	} else if (test_prefix(7, mca)) {
 		decode_memory_controller(mca, bank);
@@ -382,19 +392,25 @@ static void decode_thermal(struct mce *l
 
 void decode_intel_mc(struct mce *log, int cputype, int *ismemerr, unsigned size)
 {
+#ifdef __Linux__
 	int socket = size > offsetof(struct mce, socketid) ? (int)log->socketid : -1;
+#endif
 	int cpu = log->extcpu ? log->extcpu : log->cpu;
 
 	if (log->bank == MCE_THERMAL_BANK) { 
 		decode_thermal(log, cpu);
+#ifdef __Linux__
 		run_unknown_trigger(socket, cpu, log);
+#endif
 		return;
 	}
 
 	decode_mcg(log->mcgstatus);
+#ifdef __Linux__
 	if (decode_mci(log->status, log->misc, cpu, log->mcgcap, ismemerr,
 		socket, log->bank))
 		run_unknown_trigger(socket, cpu, log);
+#endif
 
 	if (test_prefix(11, (log->status & 0xffffL))) {
 		switch (cputype) {

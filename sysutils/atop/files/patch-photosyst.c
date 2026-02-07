--- photosyst.c.orig	2014-01-15 16:05:34 UTC
+++ photosyst.c
@@ -1118,7 +1118,11 @@ photosyst(struct sstat *si)
 	    si->cpu.nrcpu = ncpu;
 	if (si->cpu.nrcpu == 0)
 		si->cpu.nrcpu = 1;
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1200026
+	count_t forks = 0;
+#else
 	int forks = 0;
+#endif
 	GETSYSCTL("vm.stats.vm.v_forkpages", forks);
 	si->cpu.nprocs = forks;
 	GETSYSCTL("kern.smp.maxcpus", maxcpus);
@@ -1154,7 +1158,11 @@ photosyst(struct sstat *si)
 	si->cpu.lavg5	= (double) sysload.ldavg[1] / sysload.fscale;
 	si->cpu.lavg15	= (double) sysload.ldavg[2] / sysload.fscale;
 	
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1200026
+	count_t devint = 0, csw = 0;
+#else
 	int devint = 0, csw = 0;
+#endif
 	GETSYSCTL("vm.stats.sys.v_intr", devint);
 	if(devint)
 	    si->cpu.devint = devint;
@@ -1263,7 +1271,11 @@ photosyst(struct sstat *si)
 	    si->mem.freeswap=swapary[0].ksw_total - swapary[0].ksw_used;
 	}
 	/* swap statistic */
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1200026
+	count_t pswapin = 0, pswapout = 0;
+#else
 	int pswapin = 0, pswapout = 0;
+#endif
 	GETSYSCTL("vm.stats.vm.v_swapin",pswapin);
 	if(pswapin)
 	    si->mem.swins = pswapin;
@@ -1593,8 +1605,15 @@ photosyst(struct sstat *si)
 		    continue;
 
 		tcp_total++;
-		if (tp->xt_tp.t_state == TCPS_ESTABLISHED ||
-		    tp->xt_tp.t_state == TCPS_CLOSE_WAIT)
+		if (
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1200026
+		tp->t_state == TCPS_ESTABLISHED ||
+		    tp->t_state == TCPS_CLOSE_WAIT
+#else
+		tp->xt_tp.t_state == TCPS_ESTABLISHED ||
+		    tp->xt_tp.t_state == TCPS_CLOSE_WAIT
+#endif
+		)
 			tcp_count++;
 		}
 		si->net.tcp.CurrEstab = tcp_count;

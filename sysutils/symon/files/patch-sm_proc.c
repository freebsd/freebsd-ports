--- platform/FreeBSD/sm_proc.c.orig	Mon Apr 25 17:34:28 2005
+++ platform/FreeBSD/sm_proc.c	Mon Apr 25 17:34:43 2005
@@ -182,9 +182,9 @@
 		if (kvm_read(proc_kd, (unsigned long)pp->ki_paddr, &pproc,
 			     sizeof(pproc)) == sizeof(pproc)) {
 #ifdef HAS_RUSAGE_EXT
-		    cpu_uticks += pproc.p_rux.p_uticks;  /* user */
-		    cpu_sticks += pproc.p_rux.p_sticks;  /* sys  */
-		    cpu_iticks += pproc.p_rux.p_iticks;  /* int  */
+		    cpu_uticks += pproc.p_rux.rux_uticks;  /* user */
+		    cpu_sticks += pproc.p_rux.rux_sticks;  /* sys  */
+		    cpu_iticks += pproc.p_rux.rux_iticks;  /* int  */
 #else
 		    cpu_uticks += pproc.p_uticks;  /* user */
 		    cpu_sticks += pproc.p_sticks;  /* sys  */

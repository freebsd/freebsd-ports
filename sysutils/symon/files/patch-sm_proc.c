--- platform/FreeBSD/sm_proc.c.orig	Thu Mar 10 09:29:00 2005
+++ platform/FreeBSD/sm_proc.c	Thu Mar 10 09:27:52 2005
@@ -181,9 +181,15 @@
 	      if (proc_kd) {
 		   if (kvm_read(proc_kd, (unsigned long)pp->ki_paddr, &pproc,
 				  sizeof(pproc)) == sizeof(pproc)) {
+#ifdef HAS_RUSAGE_EXT
+			cpu_uticks += pproc.p_rux.rux_uticks;  /* user */
+			cpu_sticks += pproc.p_rux.rux_sticks;  /* sys  */
+			cpu_iticks += pproc.p_rux.rux_iticks;  /* int  */
+#else
 			cpu_uticks += pproc.p_uticks;  /* user */
 			cpu_sticks += pproc.p_sticks;  /* sys  */
 			cpu_iticks += pproc.p_iticks;  /* int  */
+#endif
 		   } else {
 			warning("while reading kvm: %s", kvm_geterr(proc_kd));
 		   }

--- and-OpenBSD.c.orig	Mon Jan 28 01:02:51 2002
+++ and-OpenBSD.c	Sat Dec 21 02:04:58 2002
@@ -91,17 +91,38 @@
     abort();
   }
   if (openbsd_next >= openbsd_nproc) return NULL;
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500014
+  strncpy(openbsd_proc.command,openbsd_pt[openbsd_next].ki_comm,1023);
+#else
   strncpy(openbsd_proc.command,openbsd_pt[openbsd_next].kp_proc.p_comm,1023);
+#endif
   openbsd_proc.command[1023] = 0;
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500014
+  openbsd_proc.pid = openbsd_pt[openbsd_next].ki_pid;
+  openbsd_proc.nice = openbsd_pt[openbsd_next].ki_nice-20;
+  openbsd_proc.uid = openbsd_pt[openbsd_next].ki_ruid;
+  openbsd_proc.gid = openbsd_pt[openbsd_next].ki_rgid;
+#else
   openbsd_proc.pid = openbsd_pt[openbsd_next].kp_proc.p_pid;
   openbsd_proc.nice = openbsd_pt[openbsd_next].kp_proc.p_nice-20;
   openbsd_proc.uid = openbsd_pt[openbsd_next].kp_eproc.e_pcred.p_ruid;
   openbsd_proc.gid = openbsd_pt[openbsd_next].kp_eproc.e_pcred.p_rgid;
+#endif
   /* Adapted from top(1) port, as found in the misc@openbsd.org archive */
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500014
+  /* XXX: Accessing ki_paddr causes sig10 ...
+  openbsd_proc.utime = (openbsd_pt[openbsd_next].ki_paddr->p_uticks +
+			openbsd_pt[openbsd_next].ki_paddr->p_sticks +
+			openbsd_pt[openbsd_next].ki_paddr->p_iticks)
+    / openbsd_hz;
+  */
+  openbsd_proc.utime = 0;
+#else
   openbsd_proc.utime = (openbsd_pt[openbsd_next].kp_proc.p_uticks +
 			openbsd_pt[openbsd_next].kp_proc.p_sticks +
 			openbsd_pt[openbsd_next].kp_proc.p_iticks)
     / openbsd_hz;
+#endif
   /*
     printf("%-20s  %5i  %3i  %i\n",openbsd_proc.command,openbsd_proc.pid,
     openbsd_proc.nice,openbsd_proc.utime);

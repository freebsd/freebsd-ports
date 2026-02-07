--- and-OpenBSD.c.orig	Sat Mar  6 16:34:02 2004
+++ and-OpenBSD.c	Thu Oct  6 16:11:57 2005
@@ -91,10 +91,24 @@
     abort();
   }
   if (openbsd_next >= openbsd_nproc) return NULL;
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500014
+  /* Skip kernel threads */
+  while((openbsd_pt[openbsd_next].ki_flag & P_KTHREAD) 
+	     && openbsd_next < openbsd_nproc)
+      openbsd_next++;
+  if (openbsd_next >= openbsd_nproc) return NULL;
+  strncpy(openbsd_proc.command,openbsd_pt[openbsd_next].ki_comm,1023);
+  openbsd_proc.command[1023] = 0;
+  openbsd_proc.pid = openbsd_pt[openbsd_next].ki_pid;
+  openbsd_proc.nice = openbsd_pt[openbsd_next].ki_nice-20;
+  openbsd_proc.uid = openbsd_pt[openbsd_next].ki_ruid;
+  openbsd_proc.gid = openbsd_pt[openbsd_next].ki_rgid;
+  openbsd_proc.utime = (openbsd_pt[openbsd_next].ki_runtime+500000)/1000000;
+#else
   strncpy(openbsd_proc.command,openbsd_pt[openbsd_next].kp_proc.p_comm,1023);
   openbsd_proc.command[1023] = 0;
   openbsd_proc.pid = openbsd_pt[openbsd_next].kp_proc.p_pid;
-  openbsd_proc.ppid = openbsd_pt[openbsd_next].kp_proc.p_ppid; /* FIXME that correct? */
   openbsd_proc.nice = openbsd_pt[openbsd_next].kp_proc.p_nice-20;
   openbsd_proc.uid = openbsd_pt[openbsd_next].kp_eproc.e_pcred.p_ruid;
   openbsd_proc.gid = openbsd_pt[openbsd_next].kp_eproc.e_pcred.p_rgid;
@@ -103,6 +117,7 @@
 			openbsd_pt[openbsd_next].kp_proc.p_sticks +
 			openbsd_pt[openbsd_next].kp_proc.p_iticks)
     / openbsd_hz;
+#endif
   /*
     printf("%-20s  %5i  %3i  %i\n",openbsd_proc.command,openbsd_proc.pid,
     openbsd_proc.nice,openbsd_proc.utime);

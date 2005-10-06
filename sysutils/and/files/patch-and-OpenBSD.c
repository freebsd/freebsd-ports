--- and-OpenBSD.c.orig	Sun Jan 27 18:52:18 2002
+++ and-OpenBSD.c	Thu Oct  6 14:51:53 2005
@@ -91,6 +91,21 @@
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
@@ -102,6 +117,7 @@
 			openbsd_pt[openbsd_next].kp_proc.p_sticks +
 			openbsd_pt[openbsd_next].kp_proc.p_iticks)
     / openbsd_hz;
+#endif
   /*
     printf("%-20s  %5i  %3i  %i\n",openbsd_proc.command,openbsd_proc.pid,
     openbsd_proc.nice,openbsd_proc.utime);

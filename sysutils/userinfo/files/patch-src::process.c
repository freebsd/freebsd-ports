--- src/process.c.orig	Sat Jun 14 02:33:21 2003
+++ src/process.c	Sat Jun 14 02:42:29 2003
@@ -63,15 +63,24 @@
     }
 
     for (i = 0; i < cnt; i++) {
+#if __FreeBSD_version < 500000
 	if (kp[i].kp_eproc.e_flag & EPROC_SLEADER && kp[i].kp_eproc.e_tdev !=
 		-1) {
 	    pid = kp[i].kp_proc.p_pid;
+#else
+	if (kp[i].ki_kiflag & KI_SLEADER && kp[i].ki_tdev != -1) {
+	    pid = kp[i].ki_pid;
+#endif
 	    break;
 	}
     }
 
     if (!pid)
+#if __FreeBSD_version < 500000
 	pid = kp[0].kp_eproc.e_ppid;
+#else
+	pid = kp[0].ki_ppid;
+#endif
 
     return (pid > 1) ? pid : -1;
 }

--- Process.xs.orig	2013-06-22 16:19:28 UTC
+++ Process.xs
@@ -291,7 +291,12 @@ HV *_procinfo (struct kinfo_proc *kp, in
 
     hv_store(h, "advlock",      7, newSViv(NO_FREEBSD_4x(P_FLAG(P_ADVLOCK))), 0);
     hv_store(h, "controlt",     8, newSViv(NO_FREEBSD_4x(P_FLAG(P_CONTROLT))), 0);
+
+#if __FreeBSD_version < 1100097
     hv_store(h, "kthread",      7, newSViv(NO_FREEBSD_4x(P_FLAG(P_KTHREAD))), 0);
+#else
+    hv_store(h, "kthread",      7, newSViv(NO_FREEBSD_4x(P_FLAG(P_KPROC))), 0);
+#endif
 #if __FreeBSD_version < 802501
     hv_store(h, "noload",       6, newSViv(NO_FREEBSD_4x(P_FLAG(P_NOLOAD))), 0);
 #endif

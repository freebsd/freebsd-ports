--- src/util/sss_prctl.c.orig	2026-06-09 12:32:21 UTC
+++ src/util/sss_prctl.c
@@ -53,17 +53,12 @@ int sss_prctl_set_dumpable(int dumpable)
 
 int sss_prctl_set_dumpable(int dumpable)
 {
-    dumpable = dumpable ? PROC_TRACE_CTL_ENABLE : PROC_TRACE_CTL_DISABLE;
-    return procctl(P_PID, 0, PROC_TRACE_CTL, &dumpable);
+    return 0;
 }
 
 int sss_prctl_get_dumpable(void)
 {
-    int ret, dumpable = 0;
-    ret = procctl(P_PID, 0, PROC_TRACE_STATUS, &dumpable);
-    if (ret == -1)
-        return 0;
-    return dumpable != -1; // -1 means "not dumpable"
+    return 0;
 }
 
 int sss_prctl_set_no_new_privs(void)

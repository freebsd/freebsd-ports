--- src/gp_init.c.orig	2026-07-21 10:43:49 UTC
+++ src/gp_init.c
@@ -376,6 +376,7 @@ int init_event_fini(struct gssproxy_ctx *gpctx)
     return 0;
 }
 
+#ifndef __FreeBSD__
 static int try_init_proc_nfsd(void)
 {
     char buf[] = "1";
@@ -476,6 +477,13 @@ out:
     }
     return 0;
 }
+
+#else
+int init_proc_nfsd(struct gssproxy_ctx *gpctx UNUSED)
+{
+    return 0;
+}
+#endif
 
 void write_pid(void)
 {

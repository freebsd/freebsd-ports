--- src/gp_init.c.orig	2026-10-22 17:00:59 UTC
+++ src/gp_init.c
@@ -396,6 +396,7 @@ int init_event_fini(struct gssproxy_ctx *gpctx)
     return 0;
 }
 
+#ifndef __FreeBSD__
 static int try_init_proc_nfsd(void)
 {
     char buf[] = "1";
@@ -496,6 +497,13 @@ out:
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

diff --git src/util/server.c src/util/server.c
index f34bf49f6..7cb3864af 100644
--- src/util/server.c
+++ src/util/server.c
@@ -311,10 +311,13 @@ static void setup_signals(void)
     BlockSignals(false, SIGTERM);
 
 #ifndef HAVE_PRCTL
-        /* If prctl is not defined on the system, try to handle
-         * some common termination signals gracefully */
-    CatchSignal(SIGSEGV, sig_segv_abrt);
-    CatchSignal(SIGABRT, sig_segv_abrt);
+    /* If prctl is not defined on the system, try to handle
+     * some common termination signals gracefully */
+    (void) sig_segv_abrt; /* unused */
+    /*
+      CatchSignal(SIGSEGV, sig_segv_abrt);
+      CatchSignal(SIGABRT, sig_segv_abrt);
+    */
 #endif
 
 }

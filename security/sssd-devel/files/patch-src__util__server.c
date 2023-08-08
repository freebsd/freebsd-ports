--- src/util/server.c.orig	2023-05-05 08:11:07 UTC
+++ src/util/server.c
@@ -30,17 +30,12 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <signal.h>
-#include <sys/prctl.h>
 #include <ldb.h>
 #include "util/util.h"
 #include "confdb/confdb.h"
 #include "util/sss_chain_id.h"
 #include "util/sss_chain_id_tevent.h"
 
-#ifdef HAVE_PRCTL
-#include <sys/prctl.h>
-#endif
-
 static TALLOC_CTX *autofree_ctx;
 
 static void server_atexit(void)
@@ -317,10 +312,13 @@ static void setup_signals(void)
     BlockSignals(false, SIGTERM);
 
 #ifndef HAVE_PRCTL
-        /* If prctl is not defined on the system, try to handle
-         * some common termination signals gracefully */
+    /* If prctl is not defined on the system, try to handle
+     * some common termination signals gracefully */
+    (void) sig_segv_abrt; /* unused */
+    /*
     CatchSignal(SIGSEGV, sig_segv_abrt);
     CatchSignal(SIGABRT, sig_segv_abrt);
+    */
 #endif
 
 }
@@ -747,6 +745,8 @@ int server_setup(const char *name, bool is_responder,
         DEBUG(SSSDBG_FATAL_FAILURE, "Failed to determine "CONFDB_MONITOR_DUMPABLE"\n");
         return ret;
     }
+
+#ifdef HAVE_PRCTL
     ret = prctl(PR_SET_DUMPABLE, dumpable ? 1 : 0);
     if (ret != 0) {
         DEBUG(SSSDBG_CRIT_FAILURE, "Failed to set PR_SET_DUMPABLE\n");
@@ -754,6 +754,7 @@ int server_setup(const char *name, bool is_responder,
     } else if (!dumpable) {
         DEBUG(SSSDBG_IMPORTANT_INFO, "Core dumps are disabled!\n");
     }
+#endif
 
     sss_chain_id_setup(ctx->event_ctx);
 

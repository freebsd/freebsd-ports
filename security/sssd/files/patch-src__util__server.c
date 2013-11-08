From cc6cab9e45ba978eaf33c6fa1860ee94166780be Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:21 +0100
Subject: [PATCH 22/25] patch-src__util__server.c

---
 src/util/server.c | 12 +++++++-----
 1 file changed, 7 insertions(+), 5 deletions(-)

diff --git src/util/server.c src/util/server.c
index b3073fc..ddc124f 100644
--- src/util/server.c
+++ src/util/server.c
@@ -321,12 +321,14 @@ static void setup_signals(void)
     BlockSignals(false, SIGTERM);
 
     CatchSignal(SIGHUP, sig_hup);
-
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
-- 
1.8.0


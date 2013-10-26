From 43f9d669315d710d8479b259e33d1f16afcba1d2 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:12 +0200
Subject: [PATCH 26/34] patch-src__util__server.c

---
 src/util/server.c | 11 ++++++-----
 1 file changed, 6 insertions(+), 5 deletions(-)

diff --git src/util/server.c src/util/server.c
index b3073fc..2def1f6 100644
--- src/util/server.c
+++ src/util/server.c
@@ -321,12 +321,13 @@ static void setup_signals(void)
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
+    /*
+      CatchSignal(SIGSEGV, sig_segv_abrt);
+      CatchSignal(SIGABRT, sig_segv_abrt);
+    */
 #endif
 
 }
-- 
1.8.0


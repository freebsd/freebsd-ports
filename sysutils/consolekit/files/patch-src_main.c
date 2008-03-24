--- src/main.c.orig        2007-11-08 15:05:55.000000000 -0500
+++ src/main.c        2007-11-08 15:07:39.000000000 -0500
@@ -226,6 +226,21 @@ sigusr1_handler (int sig)
 }
 
 static void
+setup_termination_signals (void)
+{
+        struct sigaction sa;
+
+        sa.sa_handler = SIG_DFL;
+        sigemptyset (&sa.sa_mask);
+        sa.sa_flags = 0;
+
+        sigaction (SIGTERM, &sa, NULL);
+        sigaction (SIGQUIT, &sa, NULL);
+        sigaction (SIGINT, &sa, NULL);
+        sigaction (SIGHUP, &sa, NULL);
+}
+
+static void
 setup_debug_log_signals (void)
 {
         struct sigaction sa;
@@ -300,6 +315,8 @@ main (int    argc,
 
         setup_debug_log (debug);
 
+        setup_termination_signals ();
+
         connection = get_system_bus ();
         if (connection == NULL) {
                 goto out;

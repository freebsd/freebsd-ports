--- src/analysisd/analysisd.c	2025-09-23 06:59:40.000000000 -0700
+++ src/analysisd/analysisd.c	2025-10-13 02:16:24.332647000 -0700
@@ -237,7 +237,11 @@
 /* Hourly alerts mutex */
 pthread_mutex_t hourly_alert_mutex = PTHREAD_MUTEX_INITIALIZER;
 /* hot reload mutes */
+#if defined(__FreeBSD__)
+static portable_rwlock_t g_hotreload_ruleset_mutex;
+#else
 static pthread_rwlock_t g_hotreload_ruleset_mutex;
+#endif
 
 /* Reported mutexes */
 static pthread_mutex_t writer_threads_mutex = PTHREAD_MUTEX_INITIALIZER;
@@ -842,11 +846,15 @@
     w_init_queues();
 
     /* Sync for event queues and API, for hot reload */
+#if defined(__FreeBSD__)
+    portable_rwlock_init(&g_hotreload_ruleset_mutex);
+#else
     pthread_rwlockattr_t rwlock_attr;
     pthread_rwlockattr_init(&rwlock_attr);
     pthread_rwlockattr_setkind_np(&rwlock_attr, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
     pthread_rwlock_init(&g_hotreload_ruleset_mutex, &rwlock_attr);
     pthread_rwlockattr_destroy(&rwlock_attr);
+#endif
 
     // Start com request thread
     w_create_thread(asyscom_main, NULL);
@@ -1226,7 +1234,11 @@
 
             result = -1;
             // take the ruleset
+#if defined(__FreeBSD__)
+            w_portable_rwlock_rdlock(&g_hotreload_ruleset_mutex);
+#else
             w_rwlock_rdlock(&g_hotreload_ruleset_mutex);
+#endif
 
             if (msg[0] == SYSCHECK_MQ) {
                 if (!queue_full(decode_queue_syscheck_input)) {
@@ -1426,8 +1438,11 @@
                 }
             }
 
-
+#if defined(__FreeBSD__)
+            w_portable_rwlock_unlock_read(&g_hotreload_ruleset_mutex);
+#else
             w_rwlock_unlock(&g_hotreload_ruleset_mutex);
+#endif
 
             if (result == -1) {
                 if (!reported_eps_drop) {
@@ -2454,7 +2469,11 @@
 
     // Sync thread for reloading ruleset,
     mdebug1("Blocking input threads to reload ruleset");
+#if defined(__FreeBSD__)
+    w_portable_rwlock_wrlock(&g_hotreload_ruleset_mutex);
+#else
     w_rwlock_wrlock(&g_hotreload_ruleset_mutex);
+#endif
 
     // Wait for a clean pipeline
     mdebug1("Wait for pipeline to be clean");
@@ -2481,7 +2500,11 @@
     w_hotreload_reload_internal_decoders();
 
     // Run the new ruleset
+#if defined(__FreeBSD__)
+    w_portable_rwlock_unlock_write(&g_hotreload_ruleset_mutex);
+#else
     w_rwlock_unlock(&g_hotreload_ruleset_mutex);
+#endif
 
     mdebug1("Unblocking input threads (Enable new ruleset)");
 

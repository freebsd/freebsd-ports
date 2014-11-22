--- pam_google_authenticator.c.orig	2014-01-30 15:17:38.000000000 +0000
+++ pam_google_authenticator.c	2014-11-04 17:05:55.000000000 +0000
@@ -503,10 +503,6 @@
 }
 #endif
 
-static int get_timestamp(void) {
-  return get_time()/30;
-}
-
 static int comparator(const void *a, const void *b) {
   return *(unsigned int *)a - *(unsigned int *)b;
 }
@@ -538,6 +534,41 @@
   return NULL;
 }
 
+#if !defined(STEPSIZE)
+static int get_timestamp(void) {
+  return get_time()/30;
+}
+#else
+static int get_timestamp(pam_handle_t *pamh, const char *secret_filename,
+                       const char *buf) {
+  const char *value = get_cfg_value(pamh, "STEP_SIZE", buf);
+  if (!value) {
+    // Default step size is 30.
+    free((void *)value);
+    return get_time()/30;
+  } else if (value == &oom) {
+    // Out of memory. This is a fatal error.
+    return 0;
+  }
+
+  char *endptr;
+  errno = 0;
+  int step = (int)strtoul(value, &endptr, 10);
+  if (errno || !*value || value == endptr ||
+      (*endptr && *endptr != ' ' && *endptr != '\t' &&
+       *endptr != '\n' && *endptr != '\r') ||
+      step < 1 || step > 60) {
+    free((void *)value);
+    log_message(LOG_ERR, pamh, "Invalid STEP_SIZE option in \"%s\"",
+                secret_filename);
+    return 0;
+  }
+  free((void *)value);
+
+  return get_time()/step;
+}
+#endif
+
 static int set_cfg_value(pam_handle_t *pamh, const char *key, const char *val,
                          char **buf) {
   size_t key_len = strlen(key);
@@ -1162,7 +1193,11 @@
   }
 
   // Compute verification codes and compare them with user input
+#if !defined(STEPSIZE)
   const int tm = get_timestamp();
+#else
+  const int tm = get_timestamp(pamh, secret_filename, *buf);
+#endif
   const char *skew_str = get_cfg_value(pamh, "TIME_SKEW", *buf);
   if (skew_str == &oom) {
     // Out of memory. This is a fatal error

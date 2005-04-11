--- src/smtp/smtp_sasl_glue.c.orig	Mon Apr 11 00:09:17 2005
+++ src/smtp/smtp_sasl_glue.c	Mon Apr 11 00:09:30 2005
@@ -321,6 +321,14 @@
 
 void    smtp_sasl_initialize(void)
 {
+    /*
+     * Global callbacks. These have no per-session context.
+     */
+    static sasl_callback_t callbacks[] = {
+	{SASL_CB_LOG, &smtp_sasl_log, 0},
+	{SASL_CB_LIST_END, 0, 0}
+    };
+
 #if SASL_VERSION_MAJOR >= 2 && (SASL_VERSION_MINOR >= 2 \
     || (SASL_VERSION_MINOR == 1 && SASL_VERSION_STEP >= 19))
     int     sasl_major;
@@ -342,14 +350,6 @@
 		  SASL_VERSION_MAJOR, SASL_VERSION_MINOR, SASL_VERSION_STEP,
 		  sasl_major, sasl_minor, sasl_step);
 #endif
-
-    /*
-     * Global callbacks. These have no per-session context.
-     */
-    static sasl_callback_t callbacks[] = {
-	{SASL_CB_LOG, &smtp_sasl_log, 0},
-	{SASL_CB_LIST_END, 0, 0}
-    };
 
     /*
      * Sanity check.

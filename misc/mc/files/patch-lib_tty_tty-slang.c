--- lib/tty/tty-slang.c.orig	2017-03-04 17:51:38 UTC
+++ lib/tty/tty-slang.c
@@ -373,7 +373,11 @@ tty_shutdown (void)
 void
 tty_enter_ca_mode (void)
 {
-    /* S-Lang handles alternate screen switching and cursor position saving */
+    if (mc_global.tty.xterm_flag)
+    {
+        fprintf (stdout, /* ESC_STR ")0" */ ESC_STR "7" ESC_STR "[?47h");
+        fflush (stdout);
+    }
 }
 
 /* --------------------------------------------------------------------------------------------- */
@@ -381,7 +385,11 @@ tty_enter_ca_mode (void)
 void
 tty_exit_ca_mode (void)
 {
-    /* S-Lang handles alternate screen switching and cursor position restoring */
+    if (mc_global.tty.xterm_flag)
+    {
+        fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
+        fflush (stdout);
+    }
 }
 
 /* --------------------------------------------------------------------------------------------- */

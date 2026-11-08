--- lib/tty/tty-slang.c.orig	2026-08-02 22:13:49 UTC
+++ lib/tty/tty-slang.c
@@ -320,7 +320,11 @@ tty_shutdown (void)
 void
 tty_enter_ca_mode (void)
 {
-    // S-Lang handles alternate screen switching and cursor position saving
+    if (mc_global.tty.xterm_flag)
+    {
+        fprintf (stdout, /* ESC_STR ")0" */ ESC_STR "7" ESC_STR "[?47h");
+        fflush (stdout);
+    }
 }
 
 /* --------------------------------------------------------------------------------------------- */
@@ -328,7 +332,11 @@ tty_enter_ca_mode (void)
 void
 tty_exit_ca_mode (void)
 {
-    // S-Lang handles alternate screen switching and cursor position restoring
+    if (mc_global.tty.xterm_flag)
+    {
+        fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
+        fflush (stdout);
+    }
 }
 
 /* --------------------------------------------------------------------------------------------- */

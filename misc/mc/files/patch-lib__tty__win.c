--- lib/tty/win.c.orig	2014-09-02 09:23:58 UTC
+++ lib/tty/win.c
@@ -107,7 +107,7 @@
 void
 do_exit_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && rmcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
         fflush (stdout);

--- lib/tty/win.c.old	2012-04-05 02:20:57.000000000 +0900
+++ lib/tty/win.c	2012-04-05 02:24:53.000000000 +0900
@@ -96,7 +96,7 @@
 void
 do_enter_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && smcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, /* ESC_STR ")0" */ ESC_STR "7" ESC_STR "[?47h");
         fflush (stdout);
@@ -108,7 +108,7 @@
 void
 do_exit_ca_mode (void)
 {
-    if (mc_global.tty.xterm_flag && rmcup != NULL)
+    if (mc_global.tty.xterm_flag)
     {
         fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
         fflush (stdout);

--- lib/tty/win.c.orig	2011-12-02 18:59:45.000000000 +0700
+++ lib/tty/win.c	2011-12-02 19:00:11.000000000 +0700
@@ -98,7 +98,7 @@
 void
 do_enter_ca_mode (void)
 {
-    if (xterm_flag && smcup != NULL)
+    if (xterm_flag)
     {
         fprintf (stdout, /* ESC_STR ")0" */ ESC_STR "7" ESC_STR "[?47h");
         fflush (stdout);
@@ -110,7 +110,7 @@
 void
 do_exit_ca_mode (void)
 {
-    if (xterm_flag && rmcup != NULL)
+    if (xterm_flag)
     {
         fprintf (stdout, ESC_STR "[?47l" ESC_STR "8" ESC_STR "[m");
         fflush (stdout);

--- src/display-console.cc.orig	2022-09-19 15:16:35 UTC
+++ src/display-console.cc
@@ -54,8 +54,11 @@ bool display_output_console::detect() {
 }
 
 bool display_output_console::detect() {
-  if ((out_to_stdout.get(*state) || out_to_stderr.get(*state)) &&
-      !out_to_ncurses.get(*state)) {
+  if ((out_to_stdout.get(*state) || out_to_stderr.get(*state))
+#ifdef BUILD_NCURSES
+      && !out_to_ncurses.get(*state)
+#endif
+  ) {
     DBGP2("Display output '%s' enabled in config.", name.c_str());
     return true;
   }

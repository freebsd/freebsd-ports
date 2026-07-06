--- lib/vscode/node_modules/node-pty/src/unix/pty.cc.orig
+++ lib/vscode/node_modules/node-pty/src/unix/pty.cc
@@ -112,7 +112,7 @@
   int exit_code = 0, signal_code = 0;
 };
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 
 static int
 SetCloseOnExec(int fd) {

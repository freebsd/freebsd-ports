--- lib/Swatch/Actions.pm.orig	2010-05-19 15:46:19.000000000 -0300
+++ lib/Swatch/Actions.pm	2010-05-19 15:47:15.000000000 -0300
@@ -96,7 +96,7 @@
 
  EXECFORK: {
     if ($exec_pid = fork) {
-      waitpid(-1, WNOHANG);
+      waitpid($exec_pid, 0);
       return 0;
     } elsif (defined $exec_pid) {
       exec($command);

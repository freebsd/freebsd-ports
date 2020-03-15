--- lib/Swatchdog/Actions.pm.orig	2015-09-29 16:39:26 UTC
+++ lib/Swatchdog/Actions.pm
@@ -96,7 +96,7 @@ sub exec_command {
 
  EXECFORK: {
     if ($exec_pid = fork) {
-      waitpid(-1, WNOHANG);
+      waitpid($exec_pid, 0);
       return 0;
     } elsif (defined $exec_pid) {
       exec($command);

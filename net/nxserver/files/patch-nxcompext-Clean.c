--- nxcompext/Clean.c	Thu Apr 29 03:00:45 2004
+++ nxcompext/Clean.c.new	Sun Sep  5 17:41:01 2004
@@ -672,7 +672,7 @@
 
   sig_act.sa_handler = &SignalHandler;
 
-  #ifdef __sun
+  #if defined(__sun) || defined(__FreeBSD__)
 
   sig_act.sa_flags = SA_SIGINFO | SA_NODEFER;
 

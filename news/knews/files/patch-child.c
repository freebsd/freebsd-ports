--- src/child.c.orig	Wed Nov  6 11:55:57 2002
+++ src/child.c	Wed Nov  6 11:57:43 2002
@@ -121,7 +121,7 @@
     flags |= SA_RESTART;
 #endif
 
-    sig_act.sa_handler = sigchld_handler;
+    sig_act.__sigaction_u.__sa_handler = sigchld_handler;
     sigemptyset(&sig_act.sa_mask);
     sigaddset(&sig_act.sa_mask, SIGCHLD);
     sig_act.sa_flags = flags;
@@ -136,27 +136,27 @@
      *  now, thanks to leo@marco.de, but I might as well keeps this.
      */
 
-    sig_act.sa_handler = SIG_IGN;
+    sig_act.__sigaction_u.__sa_handler = SIG_IGN;
     sigemptyset(&sig_act.sa_mask);
     sig_act.sa_flags = flags;
     if (sigaction(SIGPIPE, &sig_act, NULL) < 0)
 	perror("knews: sigaction(SIGPIPE)");
 
-    sig_act.sa_handler = sigfpe_handler;
+    sig_act.__sigaction_u.__sa_handler = sigfpe_handler;
     sigemptyset(&sig_act.sa_mask);
     sigaddset(&sig_act.sa_mask, SIGFPE);
     sig_act.sa_flags = flags;
     if (sigaction(SIGFPE, &sig_act, NULL) < 0)
 	perror("knews: sigaction(SIGFPE)");
 
-    sig_act.sa_handler = sighup_handler;
+    sig_act.__sigaction_u.__sa_handler = sighup_handler;
     sigemptyset(&sig_act.sa_mask);
     sigaddset(&sig_act.sa_mask, SIGHUP);
     sig_act.sa_flags = flags;
     if (sigaction(SIGHUP, &sig_act, NULL) < 0)
 	perror("knews: sigaction(SIGHUP)");
 
-    sig_act.sa_handler = sigusr1_handler;
+    sig_act.__sigaction_u.__sa_handler = sigusr1_handler;
     sigemptyset(&sig_act.sa_mask);
     sigaddset(&sig_act.sa_mask, SIGUSR1);
     sig_act.sa_flags = flags;
@@ -168,7 +168,7 @@
 {
     struct sigaction	sig_act;
 
-    sig_act.sa_handler = SIG_DFL;
+    sig_act.__sigaction_u.__sa_handler = SIG_DFL;
     sigemptyset(&sig_act.sa_mask);
     sig_act.sa_flags = 0;
     if (sigaction(SIGPIPE, &sig_act, NULL) < 0)

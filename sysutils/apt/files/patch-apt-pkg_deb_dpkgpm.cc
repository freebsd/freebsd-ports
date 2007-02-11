--- apt-pkg/deb/dpkgpm.cc.orig	Sat Sep 30 07:17:49 2006
+++ apt-pkg/deb/dpkgpm.cc	Mon Oct 23 13:42:03 2006
@@ -515,8 +515,8 @@
          it forks scripts. What happens is that when you hit ctrl-c it sends
 	 it to all processes in the group. Since dpkg ignores the signal 
 	 it doesn't die but we do! So we must also ignore it */
-      sighandler_t old_SIGQUIT = signal(SIGQUIT,SIG_IGN);
-      sighandler_t old_SIGINT = signal(SIGINT,SIG_IGN);
+      sig_t old_SIGQUIT = signal(SIGQUIT,SIG_IGN);
+      sig_t old_SIGINT = signal(SIGINT,SIG_IGN);
 	
        // Fork dpkg
       pid_t Child;

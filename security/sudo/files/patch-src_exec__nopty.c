--- src/exec_nopty.c.orig	2017-08-09 17:20:41 UTC
+++ src/exec_nopty.c
@@ -201,7 +201,7 @@ exec_nopty(struct command_details *details, struct com
 	sudo_warn(U_("unable to set handler for signal %d"), SIGCHLD);
     if (sudo_sigaction(SIGCONT, &sa, NULL) != 0)
 	sudo_warn(U_("unable to set handler for signal %d"), SIGCONT);
-#ifdef SIGINFO
+#if defined(SIGINFO) && !defined(__FreeBSD__)
     if (sudo_sigaction(SIGINFO, &sa, NULL) != 0)
 	sudo_warn(U_("unable to set handler for signal %d"), SIGINFO);
 #endif
@@ -222,6 +222,14 @@ exec_nopty(struct command_details *details, struct com
 	sudo_warn(U_("unable to set handler for signal %d"), SIGQUIT);
     if (sudo_sigaction(SIGTSTP, &sa, NULL) != 0)
 	sudo_warn(U_("unable to set handler for signal %d"), SIGTSTP);
+#if defined(SIGINFO) && defined(__FreeBSD__)
+    /*
+     * FreeBSD's ^T will generate a SIGINFO to the controlling terminal's
+     * process group.
+     */
+    if (sudo_sigaction(SIGINFO, &sa, NULL) != 0)
+	sudo_warn(U_("unable to set handler for signal %d"), SIGINFO);
+#endif
 
     /*
      * The policy plugin's session init must be run before we fork

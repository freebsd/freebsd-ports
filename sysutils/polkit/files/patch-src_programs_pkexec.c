--- src/programs/pkexec.c.orig	2022-07-11 08:46:06 UTC
+++ src/programs/pkexec.c
@@ -37,6 +37,11 @@
 #include <sys/prctl.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <signal.h>
+#include <sys/procctl.h>
+#endif
+
 #include <glib/gi18n.h>
 
 #ifdef POLKIT_AUTHFW_PAM
@@ -729,10 +734,17 @@ main (int argc, char *argv[])
     }
 
   /* make sure we are nuked if the parent process dies */
-#ifdef __linux__
+#if defined(__linux__)
   if (prctl (PR_SET_PDEATHSIG, SIGTERM) != 0)
     {
       g_printerr ("prctl(PR_SET_PDEATHSIG, SIGTERM) failed: %s\n", g_strerror (errno));
+      goto out;
+    }
+#elif defined(__FreeBSD__)
+  int _sig = SIGTERM;
+  if (procctl (P_PID, 0, PROC_PDEATHSIG_CTL, &_sig) != 0)
+    {
+      g_printerr ("procctl(2) failed: %s\n", g_strerror (errno));
       goto out;
     }
 #else

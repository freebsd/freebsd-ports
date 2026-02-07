runit is designed to be placed in /sbin.  However, there is no reason that
PREFIX cannot be respected here, so should a user define in loader.conf this
in place, then it will still be found.

init_path=/usr/local/sbin/runit-init:/sbin/init

--- src/runit-init.c.orig	2016-08-10 20:53:15 UTC
+++ src/runit-init.c
@@ -53,6 +53,9 @@ int main (int argc, const char * const *
     /* kernel is starting init, runit does the job. */
     execve(RUNIT, (char *const *)prog, envp);
 
+    /* OK, running from PREFIX-- should be default */
+    execve(PREFIX RUNIT, (char *const *)prog, envp);
+
     /* serious error */
     strerr_die4sys(111, FATAL, "unable to start ", prog[0], ": ");
   }

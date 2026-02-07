Should the user neglect to add the symlink, rather than stick them in a
reboot loop give a warning.

--- src/runit.c.orig	2016-08-10 21:03:05 UTC
+++ src/runit.c
@@ -22,10 +22,13 @@
 #define WARNING "- runit: warning: "
 #define FATAL "- runit: fatal: "
 
-const char * const stage[3] ={
+const char * const stage[] ={
   "/etc/runit/1",
   "/etc/runit/2",
-  "/etc/runit/3" };
+  "/etc/runit/3",
+  PREFIX "/etc/runit/1",
+  PREFIX "/etc/runit/2",
+  PREFIX "/etc/runit/3" };
 
 int selfpipe[2];
 int sigc =0;
@@ -134,6 +137,13 @@ int main (int argc, const char * const *
             
       strerr_warn3(INFO, "enter stage: ", stage[st], 0);
       execve(*prog, (char *const *)prog, envp);
+      /* Try with PREFIX */
+      prog[0] = stage[st+3];
+      strerr_warn3(INFO,
+            "Trying in " PREFIX "; not found in /etc: ", stage[st], 0);
+      strerr_warn3(INFO,
+            "Must run ln -s " PREFIX "/etc/runit /etc/ to work!", stage[st], 0);
+      execve(*prog, (char *const *)prog, envp);
       strerr_die4sys(0, FATAL, "unable to start child: ", stage[st], ": ");
     }
 
@@ -229,6 +239,13 @@ int main (int argc, const char * const *
           /* child */
           strerr_warn3(INFO, "enter stage: ", prog[0], 0);
           execve(*prog, (char *const *) prog, envp);
+          /* Try with PREFIX */
+          prog[0] = stage[st+3];
+          strerr_warn3(INFO,
+            "Trying in " PREFIX "; not found: ", stage[st], 0);
+          strerr_warn3(INFO,
+            "Must run ln -s " PREFIX "/etc/runit /etc/ to work!", stage[st], 0);
+          execve(*prog, (char *const *) prog, envp);
           strerr_die4sys(0, FATAL, "unable to start child: ", prog[0], ": ");
         }
         if (wait_pid(&wstat, pid2) == -1)

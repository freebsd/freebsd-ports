--- fep_main.c	Tue Jun  4 22:01:30 2002
+++ fep_main.c	Tue Jun  4 22:01:53 2002
@@ -638,7 +638,7 @@
 
 catchsig()
 {
-    union wait status;
+    int status;
     struct rusage   ru;
 
     if (wait3 (&status, WNOHANG | WUNTRACED, &ru) != child_pid)

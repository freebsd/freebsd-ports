--- src/watchdog.c.orig	Sat Dec  6 02:47:06 2003
+++ src/watchdog.c	Sat Dec  6 02:47:34 2003
@@ -324,6 +324,8 @@
     if ((pid_t)(-1) == pgrp)
       fprintf (stderr,"cannot set session id");
 
+#elif defined(__FreeBSD__)
+    setsid();
 #else /* !SunOS */
     pgrp = setpgrp(); 
 #endif /* !SunOS */

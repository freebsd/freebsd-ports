--- plugger.c.old	Wed Feb 11 16:15:56 2004
+++ plugger.c	Wed Feb 11 16:17:04 2004
@@ -189,7 +189,7 @@
     int signum;
     alarm(0);
     if(!(THIS->flags & H_DAEMON))
-      setpgrp();
+      setpgrp(0, 0);
 
     for(signum=0;signum<NSIG;signum++) signal(signum, SIG_DFL);
 

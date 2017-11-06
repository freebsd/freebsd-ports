--- uxpgnt.c.orig	2017-03-16 03:33:18.000000000 +0000
+++ uxpgnt.c	2017-03-16 03:33:18.000000000 +0000
@@ -270,7 +270,7 @@
         /* Get out of our previous process group, to avoid being
          * blasted by passing signals. But keep our controlling tty,
          * so we can keep checking to see if we still have one. */
-        setpgrp();
+        setpgrp(0,0);
     } else {
         /* Do that, but also leave our entire session and detach from
          * the controlling tty (if any). */

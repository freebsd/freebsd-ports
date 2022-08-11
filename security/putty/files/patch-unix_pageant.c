--- unix/pageant.c.orig	2022-05-24 16:56:28 UTC
+++ unix/pageant.c
@@ -330,7 +330,7 @@ void pageant_fork_and_print_env(bool retain_tty)
         /* Get out of our previous process group, to avoid being
          * blasted by passing signals. But keep our controlling tty,
          * so we can keep checking to see if we still have one. */
-        setpgrp();
+        setpgrp(0,0);
     } else {
         /* Do that, but also leave our entire session and detach from
          * the controlling tty (if any). */

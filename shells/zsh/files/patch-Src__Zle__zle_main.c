--- ./Src/Zle/zle_main.c.orig	2012-01-13 21:55:51.773384066 +0100
+++ ./Src/Zle/zle_main.c	2012-01-13 21:56:14.530384358 +0100
@@ -1200,6 +1200,18 @@
 	putc('\r', shout);
     if (tmout)
 	alarm(tmout);
+
+    /*
+     * On some windowing systems we may enter this function before the
+     * terminal is fully opened and sized, resulting in an infinite
+     * series of SIGWINCH when the handler prints the prompt before we
+     * have done so here.  Therefore, hold any such signal until the
+     * first full refresh has completed.  The important bit is that the
+     * handler must not see zleactive = 1 until ZLE really is active.
+     * See the end of adjustwinsize() in Src/utils.c
+     */
+    queue_signals();
+
     zleactive = 1;
     resetneeded = 1;
     errflag = retflag = 0;
@@ -1209,6 +1221,8 @@
 
     zrefresh();
 
+    unqueue_signals();	/* Should now be safe to acknowledge SIGWINCH */
+
     zlecallhook("zle-line-init", NULL);
 
     zlecore();

Index: eval.c
--- eval.c	25 Nov 2004 04:36:47 -0000	1.15
+++ eval.c	7 Dec 2004 16:20:20 -0000
@@ -792,6 +792,7 @@
 		}
 		if (e->loc->argc == 0) {
 			xp->str = null;
+			xp->var = global(sp);
 			state = c == '@' ? XNULLSUB : XSUB;
 		} else {
 			xp->u.strv = (const char **) e->loc->argv + 1;

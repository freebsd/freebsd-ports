Index: pool.c
===================================================================
--- pool.c	(revision 1763)
+++ pool.c	(revision 1787)
@@ -433,7 +433,7 @@
 
 		for (i = 0; i < scoreboard->conf->maxChildren; i++) {
 			chpid = scoreboard->child[i].pid;
-			if (chpid != 0)
+			if (chpid > 0)
 				kill(chpid, SIGKILL);;
 			scoreboard_release(chpid);			
 		}

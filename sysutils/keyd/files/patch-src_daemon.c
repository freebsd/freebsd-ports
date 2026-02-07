--- src/daemon.c.orig	2025-12-19 21:03:20 UTC
+++ src/daemon.c
@@ -627,7 +627,7 @@ int run_daemon(int argc, char *argv[])
 		exit(-1);
 	}
 
-	sp.sched_priority = 49;
+	sp.sched_priority = sched_get_priority_max(SCHED_FIFO);
 	if (sched_setscheduler(0, SCHED_FIFO, &sp)) {
 		perror("sched_setscheduler");
 		exit(-1);

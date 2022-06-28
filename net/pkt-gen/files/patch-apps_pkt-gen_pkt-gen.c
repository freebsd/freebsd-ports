--- apps/pkt-gen/pkt-gen.c.orig	2022-06-08 23:21:01 UTC
+++ apps/pkt-gen/pkt-gen.c
@@ -3251,8 +3251,8 @@ out:
 		g.tx_period.tv_nsec = g.tx_period.tv_nsec % 1000000000;
 	}
 	if (g.td_type == TD_TYPE_SENDER)
-	    D("Sending %d packets every  %ld.%09ld s",
-			g.burst, g.tx_period.tv_sec, g.tx_period.tv_nsec);
+	    D("Sending %d packets every  %lld.%09ld s",
+			g.burst, (long long)g.tx_period.tv_sec, g.tx_period.tv_nsec);
 	/* Install ^C handler. */
 	global_nthreads = g.nthreads;
 	sigemptyset(&ss);

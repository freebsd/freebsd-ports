--- sa.c.orig	Tue Aug 10 17:59:10 2004
+++ sa.c	Sun Dec 12 02:40:45 2004
@@ -427,8 +427,8 @@
 	    decode_32(sa->cookies + 8), decode_32(sa->cookies + 12)));
 	LOG_DBG((cls, level, "%s: msgid %08x refcnt %d", header,
 	    decode_32(sa->message_id), sa->refcnt));
-	LOG_DBG((cls, level, "%s: life secs %llu kb %llu", header, sa->seconds,
-	    sa->kilobytes));
+	LOG_DBG((cls, level, "%s: life secs %llu kb %llu", header, (long long unsigned) sa->seconds,
+	    (long long unsigned) sa->kilobytes));
 	for (proto = TAILQ_FIRST(&sa->protos); proto;
 	    proto = TAILQ_NEXT(proto, link)) {
 		LOG_DBG((cls, level, "%s: suite %d proto %d", header,
@@ -1217,7 +1217,7 @@
 		seconds = sa->seconds * (850 + sysdep_random() % 100) / 1000;
 		LOG_DBG((LOG_TIMER, 95,
 		    "sa_setup_expirations: SA %p soft timeout in %llu seconds",
-		    sa, seconds));
+		    sa, (long long unsigned) seconds));
 		expiration.tv_sec += seconds;
 		sa->soft_death = timer_add_event("sa_soft_expire",
 		    sa_soft_expire, sa, &expiration);
@@ -1232,7 +1232,7 @@
 		gettimeofday(&expiration, 0);
 		LOG_DBG((LOG_TIMER, 95,
 		    "sa_setup_expirations: SA %p hard timeout in %llu seconds",
-		    sa, sa->seconds));
+		    sa, (long long unsigned) sa->seconds));
 		expiration.tv_sec += sa->seconds;
 		sa->death = timer_add_event("sa_hard_expire", sa_hard_expire,
 		    sa, &expiration);

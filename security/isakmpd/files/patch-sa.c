--- sa.c.orig	Wed Nov 13 04:31:38 2002
+++ sa.c	Sat Feb  8 12:04:21 2003
@@ -440,6 +440,6 @@
   LOG_DBG ((cls, level, "%s: msgid %08x refcnt %d", header,
 	    decode_32 (sa->message_id), sa->refcnt));
-  LOG_DBG ((cls, level, "%s: life secs %llu kb %llu", header, sa->seconds,
-	    sa->kilobytes));
+  LOG_DBG ((cls, level, "%s: life secs %llu kb %llu", header, (long long unsigned) sa->seconds,
+	    (long long unsigned) sa->kilobytes));
   for (proto = TAILQ_FIRST (&sa->protos); proto;
        proto = TAILQ_NEXT (proto, link))
@@ -1040,5 +1040,5 @@
       LOG_DBG ((LOG_TIMER, 95,
 		"sa_setup_expirations: SA %p soft timeout in %llu seconds",
-		sa, seconds));
+		sa, (long long unsigned) seconds));
       expiration.tv_sec += seconds;
       sa->soft_death
@@ -1058,5 +1058,5 @@
       LOG_DBG ((LOG_TIMER, 95,
 		"sa_setup_expirations: SA %p hard timeout in %llu seconds",
-		sa, sa->seconds));
+		sa, (long long unsigned) sa->seconds));
       expiration.tv_sec += sa->seconds;
       sa->death

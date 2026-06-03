--- src/pipewire/context.c.orig	2026-03-16 11:54:17 UTC
+++ src/pipewire/context.c
@@ -351,17 +351,19 @@ static int adjust_rlimits(const struct spa_dict *dict)
 		[RLIMIT_CPU]        = "cpu",
 		[RLIMIT_DATA]       = "data",
 		[RLIMIT_FSIZE]      = "fsize",
-		[RLIMIT_LOCKS]      = "locks",
 		[RLIMIT_MEMLOCK]    = "memlock",
-		[RLIMIT_MSGQUEUE]   = "msgqueue",
-		[RLIMIT_NICE]       = "nice",
 		[RLIMIT_NOFILE]     = "nofile",
 		[RLIMIT_NPROC]      = "nproc",
 		[RLIMIT_RSS]        = "rss",
+		[RLIMIT_STACK]      = "stack",
+#ifdef __linux__
+		[RLIMIT_LOCKS]      = "locks",
+		[RLIMIT_MSGQUEUE]   = "msgqueue",
+		[RLIMIT_NICE]       = "nice",
 		[RLIMIT_RTPRIO]     = "rtprio",
 		[RLIMIT_RTTIME]     = "rttime",
 		[RLIMIT_SIGPENDING] = "sigpending",
-		[RLIMIT_STACK]      = "stack",
+#endif
 	};
 	int res;
 	spa_dict_for_each(it, dict) {

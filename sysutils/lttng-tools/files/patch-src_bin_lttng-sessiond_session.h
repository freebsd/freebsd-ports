--- src/bin/lttng-sessiond/session.h.orig	2017-01-09 19:26:28 UTC
+++ src/bin/lttng-sessiond/session.h
@@ -60,7 +60,7 @@ struct ltt_session_list {
  */
 struct ltt_session {
 	char name[NAME_MAX];
-	char hostname[HOST_NAME_MAX]; /* Local hostname. */
+	char hostname[_POSIX_HOST_NAME_MAX]; /* Local hostname. */
 	struct ltt_kernel_session *kernel_session;
 	struct ltt_ust_session *ust_session;
 	/*

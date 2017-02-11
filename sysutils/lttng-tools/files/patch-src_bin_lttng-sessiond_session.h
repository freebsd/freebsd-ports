--- src/bin/lttng-sessiond/session.h.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-sessiond/session.h
@@ -60,7 +60,11 @@ struct ltt_session_list {
  */
 struct ltt_session {
 	char name[NAME_MAX];
+#if defined(__FreeBSD__)
+	char hostname[256]; /* Local hostname. */
+#else
 	char hostname[HOST_NAME_MAX]; /* Local hostname. */
+#endif
 	struct ltt_kernel_session *kernel_session;
 	struct ltt_ust_session *ust_session;
 	/*

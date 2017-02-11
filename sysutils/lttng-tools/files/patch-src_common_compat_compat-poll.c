--- src/common/compat/compat-poll.c.orig	2017-01-13 22:38:05 UTC
+++ src/common/compat/compat-poll.c
@@ -112,7 +112,11 @@ int compat_poll_create(struct lttng_poll
 
 	if (!poll_max_size) {
 		ERR("poll_max_size not initialized yet");
+#if defined(__FreeBSD__)
+		poll_max_size = DEFAULT_POLL_SIZE;
+#else
 		goto error;
+#endif
 	}
 
 	/* Don't bust the limit here */

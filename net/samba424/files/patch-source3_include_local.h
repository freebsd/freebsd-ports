--- source3/include/local.h.orig	2026-01-20 15:42:54 UTC
+++ source3/include/local.h
@@ -131,7 +131,18 @@
 #define WINBIND_SERVER_MUTEX_WAIT_TIME (( ((NUM_CLI_AUTH_CONNECT_RETRIES) * ((CLI_AUTH_TIMEOUT)/1000)) + 5)*2)
 
 /* size of listen() backlog in smbd */
+#if defined (FREEBSD)
+#define SMBD_LISTEN_BACKLOG -1
+#else
 #define SMBD_LISTEN_BACKLOG 50
+#endif
+
+/* size of listen() default backlog */
+#if defined (FREEBSD)
+#define DEFAULT_LISTEN_BACKLOG -1
+#else
+#define DEFAULT_LISTEN_BACKLOG 5
+#endif
 
 /* Number of microseconds to wait before a sharing violation. */
 #define SHARING_VIOLATION_USEC_WAIT 950000

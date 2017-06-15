--- daemon/http-tx-mgr.c.orig	2015-09-21 03:42:11 UTC
+++ daemon/http-tx-mgr.c
@@ -58,6 +58,22 @@
 #define USER_AGENT_OS "Linux"
 #endif
 
+#ifdef __FreeBSD__
+#define USER_AGENT_OS "FreeBSD"
+#endif
+
+#ifdef __DragonFly__
+#define USER_AGENT_OS "DragonFly"
+#endif
+
+#ifdef __NetBSD__
+#define USER_AGENT_OS "NetBSD"
+#endif
+
+#ifdef __OpenBSD__
+#define USER_AGENT_OS "OpenBSD"
+#endif
+
 struct _Connection {
     CURL *curl;
     gint64 ctime;               /* Used to clean up unused connection. */

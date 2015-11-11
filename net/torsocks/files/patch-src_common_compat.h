--- src/common/compat.h.orig	2015-05-27 18:54:22 UTC
+++ src/common/compat.h
@@ -187,6 +187,10 @@ void tsocks_once(tsocks_once_t *o, void 
 #define TSOCKS_NR_GETPEERNAME SYS_getpeername
 #define TSOCKS_NR_LISTEN    SYS_listen
 #define TSOCKS_NR_RECVMSG   SYS_recvmsg
+#if defined(__FreeBSD__)
+#define TSOCKS_NR_GETPID    SYS_getpid
+#define TSOCKS_NR_FORK      SYS_fork
+#endif
 
 #endif /* __FreeBSD__, __FreeBSD_kernel__, __darwin__, __NetBSD__ */
 

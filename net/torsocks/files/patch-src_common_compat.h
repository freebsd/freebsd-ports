--- src/common/compat.h.orig	2018-04-20 15:41:42 UTC
+++ src/common/compat.h
@@ -214,6 +214,10 @@ void tsocks_once(tsocks_once_t *o, void 
 #define TSOCKS_NR_GETPEERNAME SYS_getpeername
 #define TSOCKS_NR_LISTEN    SYS_listen
 #define TSOCKS_NR_RECVMSG   SYS_recvmsg
+#if defined(__FreeBSD__)
+#define TSOCKS_NR_GETPID    SYS_getpid
+#define TSOCKS_NR_FORK      SYS_fork
+#endif
 
 #endif /* __FreeBSD__, __FreeBSD_kernel__, __darwin__, __NetBSD__ */
 

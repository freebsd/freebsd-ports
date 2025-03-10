--- src/lib/recv.c.orig	2024-08-24 03:06:10 UTC
+++ src/lib/recv.c
@@ -173,6 +173,8 @@ error:
 	return ret;
 }
 
+#if __FreeBSD_cc_version < 1500000
+
 /*
  * Libc hijacked symbol recvmsg(2).
  */
@@ -186,3 +188,5 @@ LIBC_RECVMSG_DECL
 
 	return tsocks_recvmsg(LIBC_RECVMSG_ARGS);
 }
+
+#endif

- workaround for https://gitlab.torproject.org/tpo/core/torsocks/-/issues/40023

--- src/lib/getpeername.c.orig	2022-05-25 14:36:05 UTC
+++ src/lib/getpeername.c
@@ -92,6 +92,8 @@ libc:
 	return tsocks_libc_getpeername(LIBC_GETPEERNAME_ARGS);
 }
 
+#if __FreeBSD_cc_version < 1500000
+
 /*
  * Libc hijacked symbol getpeername(2).
  */
@@ -105,3 +107,5 @@ LIBC_GETPEERNAME_DECL
 
 	return tsocks_getpeername(LIBC_GETPEERNAME_ARGS);
 }
+
+#endif

- workaround for https://gitlab.torproject.org/tpo/core/torsocks/-/issues/40023

--- src/lib/getpeername.c.orig	2024-07-25 16:31:28 UTC
+++ src/lib/getpeername.c
@@ -22,6 +22,8 @@
 
 #include "torsocks.h"
 
+#if __FreeBSD_cc_version < 1500000
+
 /* getpeername(2) */
 TSOCKS_LIBC_DECL(getpeername, LIBC_GETPEERNAME_RET_TYPE,
 		LIBC_GETPEERNAME_SIG)
@@ -105,3 +107,5 @@ LIBC_GETPEERNAME_DECL
 
 	return tsocks_getpeername(LIBC_GETPEERNAME_ARGS);
 }
+
+#endif

--- md-386.h.orig	2023-02-15 05:01:08 UTC
+++ md-386.h
@@ -0,0 +1,16 @@
+#define TCPDUMP_ALIGN
+
+#include <machine/endian.h>
+
+/* 32-bit data types */
+/* N.B.: this doesn't address printf()'s %d vs. %ld formats */
+/*
+typedef	long	int32;		
+*/
+/* signed 32-bit integer */
+#ifndef	AUTH_UNIX
+/*
+typedef	u_long	u_int32;	
+*/
+/* unsigned 32-bit integer */
+#endif


$FreeBSD$

--- softflowd.c.orig
+++ softflowd.c
@@ -91,6 +91,9 @@
 #ifdef DLT_LOOP
 	{ DLT_LOOP,	 4,  0,  4,  1, 0xffffffff, AF_INET, AF_INET6 },
 #endif
+#ifdef DLT_PFLOG
+	{ DLT_PFLOG,    48,  1,  1,  0, 0x000000ff, AF_INET, AF_INET6 },
+#endif
 	{ -1,		-1, -1, -1, -1, 0x00000000,  0xffff,   0xffff },
 };
 

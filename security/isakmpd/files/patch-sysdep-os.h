--- sysdep/freebsd/sysdep-os.h~	Fri Jan 25 14:55:21 2002
+++ sysdep/freebsd/sysdep-os.h	Tue Nov 26 14:40:03 2002
@@ -81,4 +81,11 @@
 }
 #endif
 
+#ifndef CPI_RESERVED_MAX
+#define CPI_RESERVED_MIN	1
+#define CPI_RESERVED_MAX	255
+#define CPI_PRIVATE_MIN		61440
+#define CPI_PRIVATE_MAX		65536
+#endif
+
 #endif /* _SYSDEP_OS_H_ */

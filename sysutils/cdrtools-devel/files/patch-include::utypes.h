--- include/utypes.h	Sat Feb 18 18:56:17 2006
+++ include/utypes.h	Sat Feb 18 18:57:04 2006
@@ -380,7 +380,9 @@
 #endif
 
 #define	SIZE_T_MIN	TYPE_MINVAL(size_t)
+#ifndef SIZE_T_MAX
 #define	SIZE_T_MAX	TYPE_MAXVAL(size_t)
+#endif
 
 #define	SSIZE_T_MIN	TYPE_MINVAL(ssize_t)
 #define	SSIZE_T_MAX	TYPE_MAXVAL(ssize_t)

--- trio/triop.h.orig	2015-03-30 17:21:24.000000000 +0900
+++ trio/triop.h	2015-07-21 06:00:48.713329000 +0900
@@ -404,7 +404,11 @@
 void trio_unregister TRIO_PROTO((trio_pointer_t handle));
 
 TRIO_CONST char *trio_get_format TRIO_PROTO((trio_pointer_t ref));
+#if !defined(__llvm__)
+trio_pointer_t trio_get_argument TRIO_PROTO((trio_pointer_t ref));
+#else
 TRIO_CONST trio_pointer_t trio_get_argument TRIO_PROTO((trio_pointer_t ref));
+#endif
 
 /* Modifiers */
 int  trio_get_width TRIO_PROTO((trio_pointer_t ref));

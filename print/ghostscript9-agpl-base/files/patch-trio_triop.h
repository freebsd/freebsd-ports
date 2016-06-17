--- trio/triop.h.orig	2015-03-30 08:21:24 UTC
+++ trio/triop.h
@@ -404,7 +404,11 @@ trio_pointer_t trio_register TRIO_PROTO(
 void trio_unregister TRIO_PROTO((trio_pointer_t handle));
 
 TRIO_CONST char *trio_get_format TRIO_PROTO((trio_pointer_t ref));
+#if !defined(__llvm__)
+trio_pointer_t trio_get_argument TRIO_PROTO((trio_pointer_t ref));
+#else
 TRIO_CONST trio_pointer_t trio_get_argument TRIO_PROTO((trio_pointer_t ref));
+#endif
 
 /* Modifiers */
 int  trio_get_width TRIO_PROTO((trio_pointer_t ref));

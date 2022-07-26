--- unwind_prot.c.orig	2022-06-22 11:14:12.384859000 -0700
+++ unwind_prot.c	2022-06-22 11:14:56.970599000 -0700
@@ -55,6 +55,9 @@
 typedef struct {
   char *variable;
   int size;
+#ifdef __CHERI_PURE_CAPABILITY__
+  _Alignas(max_align_t)
+#endif
   char desired_setting[1]; /* actual size is `size' */
 } SAVED_VAR;
 

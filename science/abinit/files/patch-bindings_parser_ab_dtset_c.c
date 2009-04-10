--- bindings/parser/ab_dtset_c.c.orig	2009-02-22 07:08:32.000000000 +0100
+++ bindings/parser/ab_dtset_c.c	2009-03-26 22:21:33.000000000 +0100
@@ -7,6 +7,8 @@
 /* g95 : #define FC_MOD_NAME(A) ab_dtset_MP_ ## A */
 #define FC_MOD_CALL(A,...) FC_MOD_NAME(A)(__VA_ARGS__)
 
+typedef unsigned int uint;
+
 /* Fortran interface. */
 void FC_MOD_NAME(ab_dtset_new)(int *dt, const char *filename, int *len);
 void FC_MOD_NAME(ab_dtset_new_from_string)(int *dt, const char *string, int *len);

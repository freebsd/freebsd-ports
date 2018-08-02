--- gsl/mlgsl_error.c.orig	2014-04-12 01:43:31 UTC
+++ gsl/mlgsl_error.c
@@ -34,6 +34,7 @@ static value       *ml_gsl_exn;
 
 static void ml_gsl_raise_exn(const char *msg, int gsl_errno)
 {
+  CAMLparam0();
   CAMLlocal2(exn_msg, exn_arg);
   exn_msg = copy_string(msg);
   exn_arg = alloc_small(2, 0);

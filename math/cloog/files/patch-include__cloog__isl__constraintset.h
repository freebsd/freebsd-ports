--- ./include/cloog/isl/constraintset.h.orig	2013-10-11 04:27:03.000000000 -0300
+++ ./include/cloog/isl/constraintset.h	2014-07-07 20:50:52.000000000 -0300
@@ -27,6 +27,12 @@
 CloogConstraint *cloog_constraint_from_isl_constraint(struct isl_constraint *constraint);
 isl_constraint *cloog_constraint_to_isl(CloogConstraint *constraint);
 
+__isl_give isl_val *cloog_int_to_isl_val(isl_ctx* ctx, cloog_int_t c);
+void isl_val_to_cloog_int(__isl_keep isl_val *val, cloog_int_t *cint);
+
+__isl_give isl_val *cloog_constraint_coefficient_get_val(CloogConstraint *constraint,
+			int var);
+
 #if defined(__cplusplus)
   }
 #endif 

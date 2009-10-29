--- src/HOL/Tools/int_factor_simprocs.ML.orig	2009-10-17 19:46:40.000000000 +1100
+++ src/HOL/Tools/int_factor_simprocs.ML	2009-10-17 20:06:01.000000000 +1100
@@ -29,7 +29,7 @@
   struct
   val mk_coeff          = mk_coeff
   val dest_coeff        = dest_coeff 1
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   val norm_ss1 = HOL_ss addsimps minus_from_mult_simps @ mult_1s
   val norm_ss2 = HOL_ss addsimps simps @ mult_minus_simps
@@ -249,7 +249,7 @@
   val mk_coeff          = mk_coeff
   val dest_coeff        = dest_coeff
   val find_first        = find_first_t []
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
   val norm_ss = HOL_ss addsimps mult_1s @ @{thms mult_ac}
   fun norm_tac ss = ALLGOALS (simp_tac (Simplifier.inherit_context ss norm_ss))
   val simplify_meta_eq  = cancel_simplify_meta_eq 
@@ -261,7 +261,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_eq
   val dest_bal = HOLogic.dest_bin "op =" Term.dummyT
-  val simp_conv = K (K (SOME @{thm mult_cancel_left}))
+  fun simp_conv _ _ = SOME @{thm mult_cancel_left}
 );
 
 (*for ordered rings*)
@@ -290,7 +290,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binop @{const_name Divides.div}
   val dest_bal = HOLogic.dest_bin @{const_name Divides.div} HOLogic.intT
-  val simp_conv = K (K (SOME @{thm zdiv_zmult_zmult1_if}))
+  fun simp_conv _ _ = SOME @{thm zdiv_zmult_zmult1_if}
 );
 
 structure IntModCancelFactor = ExtractCommonTermFun
@@ -298,7 +298,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binop @{const_name Divides.mod}
   val dest_bal = HOLogic.dest_bin @{const_name Divides.mod} HOLogic.intT
-  val simp_conv = K (K (SOME @{thm zmod_zmult_zmult1}))
+  fun simp_conv _ _ = SOME @{thm zmod_zmult_zmult1}
 );
 
 structure IntDvdCancelFactor = ExtractCommonTermFun
@@ -306,7 +306,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binrel @{const_name Ring_and_Field.dvd}
   val dest_bal = HOLogic.dest_bin @{const_name Ring_and_Field.dvd} Term.dummyT
-  val simp_conv = K (K (SOME @{thm dvd_mult_cancel_left}))
+  fun simp_conv _ _ = SOME @{thm dvd_mult_cancel_left}
 );
 
 (*Version for all fields, including unordered ones (type complex).*)
@@ -315,7 +315,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binop @{const_name HOL.divide}
   val dest_bal = HOLogic.dest_bin @{const_name HOL.divide} Term.dummyT
-  val simp_conv = K (K (SOME @{thm mult_divide_mult_cancel_left_if}))
+  fun simp_conv _ _ = SOME @{thm mult_divide_mult_cancel_left_if}
 );
 
 val cancel_factors =

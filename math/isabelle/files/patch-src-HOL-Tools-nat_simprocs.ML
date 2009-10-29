--- src/HOL/Tools/nat_simprocs.ML.orig	2009-10-17 19:48:52.000000000 +1100
+++ src/HOL/Tools/nat_simprocs.ML	2009-10-18 09:59:34.000000000 +1100
@@ -142,7 +142,7 @@
   val mk_coeff          = mk_coeff
   val dest_coeff        = dest_coeff
   val find_first_coeff  = find_first_coeff []
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   val norm_ss1 = Int_Numeral_Simprocs.num_ss addsimps numeral_syms @ add_0s @ mult_1s @
     [@{thm Suc_eq_add_numeral_1_left}] @ @{thms add_ac}
@@ -231,7 +231,7 @@
   val dest_coeff        = dest_coeff
   val left_distrib      = @{thm left_add_mult_distrib} RS trans
   val prove_conv        = Arith_Data.prove_conv_nohyps
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   val norm_ss1 = Int_Numeral_Simprocs.num_ss addsimps numeral_syms @ add_0s @ mult_1s @ [@{thm Suc_eq_add_numeral_1}] @ @{thms add_ac}
   val norm_ss2 = Int_Numeral_Simprocs.num_ss addsimps bin_simps @ @{thms add_ac} @ @{thms mult_ac}
@@ -256,7 +256,7 @@
   struct
   val mk_coeff          = mk_coeff
   val dest_coeff        = dest_coeff
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   val norm_ss1 = Int_Numeral_Simprocs.num_ss addsimps
     numeral_syms @ add_0s @ mult_1s @ [@{thm Suc_eq_add_numeral_1_left}] @ @{thms add_ac}
@@ -362,7 +362,7 @@
   val mk_coeff          = mk_coeff
   val dest_coeff        = dest_coeff
   val find_first        = find_first_t []
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
   val norm_ss = HOL_ss addsimps mult_1s @ @{thms mult_ac}
   fun norm_tac ss = ALLGOALS (simp_tac (Simplifier.inherit_context ss norm_ss))
   val simplify_meta_eq  = cancel_simplify_meta_eq
@@ -373,7 +373,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_eq
   val dest_bal = HOLogic.dest_bin "op =" HOLogic.natT
-  val simp_conv = K(K (SOME @{thm nat_mult_eq_cancel_disj}))
+  fun simp_conv _ _ = SOME @{thm nat_mult_eq_cancel_disj}
 );
 
 structure LessCancelFactor = ExtractCommonTermFun
@@ -381,7 +381,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binrel @{const_name HOL.less}
   val dest_bal = HOLogic.dest_bin @{const_name HOL.less} HOLogic.natT
-  val simp_conv = K(K (SOME @{thm nat_mult_less_cancel_disj}))
+  fun simp_conv _ _ = SOME @{thm nat_mult_less_cancel_disj}
 );
 
 structure LeCancelFactor = ExtractCommonTermFun
@@ -389,7 +389,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binrel @{const_name HOL.less_eq}
   val dest_bal = HOLogic.dest_bin @{const_name HOL.less_eq} HOLogic.natT
-  val simp_conv = K(K (SOME @{thm nat_mult_le_cancel_disj}))
+  fun simp_conv _ _ = SOME @{thm nat_mult_le_cancel_disj}
 );
 
 structure DivideCancelFactor = ExtractCommonTermFun
@@ -397,7 +397,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binop @{const_name Divides.div}
   val dest_bal = HOLogic.dest_bin @{const_name Divides.div} HOLogic.natT
-  val simp_conv = K(K (SOME @{thm nat_mult_div_cancel_disj}))
+  fun simp_conv _ _ = SOME @{thm nat_mult_div_cancel_disj}
 );
 
 structure DvdCancelFactor = ExtractCommonTermFun
@@ -405,7 +405,7 @@
   val prove_conv = Arith_Data.prove_conv
   val mk_bal   = HOLogic.mk_binrel @{const_name Ring_and_Field.dvd}
   val dest_bal = HOLogic.dest_bin @{const_name Ring_and_Field.dvd} HOLogic.natT
-  val simp_conv = K(K (SOME @{thm nat_mult_dvd_cancel_disj}))
+  fun simp_conv _ _ = SOME @{thm nat_mult_dvd_cancel_disj}
 );
 
 val cancel_factor =

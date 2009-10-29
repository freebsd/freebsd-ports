--- src/HOL/Tools/int_arith.ML.orig	2009-04-17 01:29:56.000000000 +1000
+++ src/HOL/Tools/int_arith.ML	2009-10-17 19:35:35.000000000 +1100
@@ -229,7 +229,7 @@
   val mk_coeff          = mk_coeff
   val dest_coeff        = dest_coeff 1
   val find_first_coeff  = find_first_coeff []
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   fun norm_tac ss =
     ALLGOALS (simp_tac (Simplifier.inherit_context ss norm_ss1))
@@ -308,7 +308,7 @@
   val dest_coeff        = dest_coeff 1
   val left_distrib      = @{thm combine_common_factor} RS trans
   val prove_conv        = Arith_Data.prove_conv_nohyps
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   fun norm_tac ss =
     ALLGOALS (simp_tac (Simplifier.inherit_context ss norm_ss1))
@@ -334,7 +334,7 @@
   val dest_coeff        = dest_fcoeff 1
   val left_distrib      = @{thm combine_common_factor} RS trans
   val prove_conv        = Arith_Data.prove_conv_nohyps
-  val trans_tac         = K Arith_Data.trans_tac
+  fun trans_tac _       = Arith_Data.trans_tac
 
   val norm_ss1a = norm_ss1 addsimps inverse_1s @ divide_simps
   fun norm_tac ss =

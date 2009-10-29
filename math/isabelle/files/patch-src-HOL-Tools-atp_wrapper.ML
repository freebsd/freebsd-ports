--- src/HOL/Tools/atp_wrapper.ML.orig	2009-10-18 11:13:04.000000000 +1100
+++ src/HOL/Tools/atp_wrapper.ML	2009-10-18 11:14:20.000000000 +1100
@@ -112,13 +112,13 @@
 fun tptp_prover_opts max_new theory_const =
   tptp_prover_opts_full max_new theory_const false;
 
-val tptp_prover = tptp_prover_opts 60 true;
+fun tptp_prover x = tptp_prover_opts 60 true x;
 
 (*for structured proofs: prover must support TSTP*)
 fun full_prover_opts max_new theory_const =
   tptp_prover_opts_full max_new theory_const true;
 
-val full_prover = full_prover_opts 60 true;
+fun full_prover x = full_prover_opts 60 true x;
 
 
 (* Vampire *)

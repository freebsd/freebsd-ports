--- src/Ubern.cc.orig	2021-02-21 22:27:49 UTC
+++ src/Ubern.cc
@@ -115,7 +115,7 @@ B(-Z)=Z+B(Z)\n")
 
 
   NDArray X ( args(0).array_value() );
-  octave_idx_type lx = X.length();
+  octave_idx_type lx = X.numel();
 
   NDArray BP(X),BN(X);  
  

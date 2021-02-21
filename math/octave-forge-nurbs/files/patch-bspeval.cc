--- bspeval.cc.orig	2021-02-21 22:35:52 UTC
+++ bspeval.cc
@@ -113,7 +113,7 @@ static bool bspeval_bad_arguments (const octave_value_
       error("bspeval: the knot vector should be a real vector."); 
       return true; 
     } 
-  if (!args(3).is_real_type()) 
+  if (!args(3).isreal()) 
     { 
       error("bspeval: the set of parametric points should be an array of doubles."); 
       return true; 

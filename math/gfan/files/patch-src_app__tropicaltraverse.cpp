--- src/app_tropicaltraverse.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/app_tropicaltraverse.cpp
@@ -93,8 +93,8 @@ class TropicalTraverseApplication : public GFanApplica
 	s.computeClosure(generators);
 	  s.createTrie();
 
-	  log2 s.print(Stderr);
-	log2 fprintf(Stderr,"\n");
+	  gfan_log2 s.print(Stderr);
+	gfan_log2 fprintf(Stderr,"\n");
       }
     if(optionTorusSymmetry.getValue() && !optionSymmetry.getValue())
       {

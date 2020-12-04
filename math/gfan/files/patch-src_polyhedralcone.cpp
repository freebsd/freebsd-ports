--- src/polyhedralcone.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/polyhedralcone.cpp
@@ -879,7 +879,7 @@ IntegerVectorList PolyhedralCone::extremeRays(IntegerV
 	    ret.push_back(u);
 	  else
 	    {
-	      log2 fprintf(Stderr,"Remember to fix cdd double description interface\n");
+	      gfan_log2 fprintf(Stderr,"Remember to fix cdd double description interface\n");
 	    }
 	}
     }

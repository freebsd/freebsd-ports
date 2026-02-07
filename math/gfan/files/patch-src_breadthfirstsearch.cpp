--- src/breadthfirstsearch.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/breadthfirstsearch.cpp
@@ -259,7 +259,7 @@ class Orbit{ (public)
 	//	fprintf(Stderr,"1b\n");
       }
 
-    log2 fprintf(Stderr,"numFixed = %i\n",numFixed);
+    gfan_log2 fprintf(Stderr,"numFixed = %i\n",numFixed);
     return groupSize/numFixed;
   }
 };
@@ -368,7 +368,7 @@ void BreadthFirstSearch::enumerate(const PolynomialSet
 	static int n;
 	n++;
 	if(!(n%10))
-	  log2 fprintf(Stderr,"%i\n",n);
+	  gfan_log2 fprintf(Stderr,"%i\n",n);
       }
        log3  fprintf(Stderr,"Active set:\n");
        log3 active.print(Stderr);
@@ -484,7 +484,7 @@ void BreadthFirstSearch::enumerate(const PolynomialSet
 		    }
 		  else
 		    {
-		      // log2 fprintf(Stderr,"-- marked\n");
+		      // gfan_log2 fprintf(Stderr,"-- marked\n");
 		    }
 		}
 	    }

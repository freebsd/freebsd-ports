diff -Naur src/Parser/Params/dtd.sml.orig src/Parser/Params/dtd.sml
--- src/Parser/Params/dtd.sml.orig	2003-10-09 09:47:56.000000000 -0500
+++ src/Parser/Params/dtd.sml	2003-10-17 14:09:57.000000000 -0500
@@ -290,10 +290,10 @@
 	    val _ = map (fn i => Array.update(preRedef,i,false)) [1,2,3,4,5]
 	    val _ = GenEnt2Index dtd [0wx2D] (* "-" *)
 	    val _ = ParEnt2Index dtd [0wx2D] (* "-" *)
-	    val _ = Vector.appi 
-	       (fn (_,(name,lit,cs)) 
-		=> (setGenEnt dtd (GenEnt2Index dtd name,(GE_INTERN(lit,cs),false)))) 
-	       (predefined,1,NONE)
+            val _ = VectorSlice.appi 
+               (fn (_,(name,lit,cs)) 
+                => (setGenEnt dtd (GenEnt2Index dtd name,(GE_INTERN(lit,cs),false))))
+               (VectorSlice.slice (predefined,1,NONE))
 	 in ()
 	 end
 

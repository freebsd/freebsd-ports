diff -Naur src/Parser/Dfa/dfaPassTwo.sml.orig src/Parser/Dfa/dfaPassTwo.sml
--- src/Parser/Dfa/dfaPassTwo.sml.orig	2003-10-09 09:47:55.000000000 -0500
+++ src/Parser/Dfa/dfaPassTwo.sml	2003-10-17 14:24:41.000000000 -0500
@@ -72,6 +72,6 @@
 
 	    val _ = do_cm (nil,true) cmi
 
-	 in Array.extract (table,0,NONE)
+	 in Array.vector table
 	 end
     end

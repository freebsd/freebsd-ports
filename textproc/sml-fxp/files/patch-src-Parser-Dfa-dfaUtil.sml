diff -Naur src/Parser/Dfa/dfaUtil.sml.orig src/Parser/Dfa/dfaUtil.sml
--- src/Parser/Dfa/dfaUtil.sml.orig	2003-10-09 09:47:54.000000000 -0500
+++ src/Parser/Dfa/dfaUtil.sml	2003-10-17 14:22:35.000000000 -0500
@@ -124,7 +124,7 @@
 	    val tab = Array.array(hi-lo+1,dfaError)
 	    val _ = app (fn (q,a) => Array.update (tab,a-lo,q)) flw
 	 in 
-	    (lo,hi,Array.extract (tab,0,NONE),fin)
+	    (lo,hi,Array.vector tab,fin)
 	 end
 
    end

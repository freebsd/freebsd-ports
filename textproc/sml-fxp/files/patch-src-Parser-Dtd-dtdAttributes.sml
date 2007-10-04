diff -Naur src/Parser/Dtd/dtdAttributes.sml.orig src/Parser/Dtd/dtdAttributes.sml
--- src/Parser/Dtd/dtdAttributes.sml.orig	2003-10-09 09:47:55.000000000 -0500
+++ src/Parser/Dtd/dtdAttributes.sml	2003-10-17 14:12:28.000000000 -0500
@@ -65,7 +65,7 @@
 				     ord(String.sub(s,1))-65,
 				     true)) 
 	       iso639codes
-	 in Vector.tabulate(26,fn i => Array.extract (Array.sub(arr,i),0,NONE))
+	 in Vector.tabulate(26,fn i => Array.vector (Array.sub(arr,i)))
 	 end
 
       (*--------------------------------------------------------------------*)

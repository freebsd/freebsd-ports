diff -Naur src/Apps/Copy/copyEncode.sml.orig src/Apps/Copy/copyEncode.sml
--- src/Apps/Copy/copyEncode.sml.orig	2003-10-09 09:48:00.000000000 -0500
+++ src/Apps/Copy/copyEncode.sml	2003-10-17 14:30:01.000000000 -0500
@@ -126,7 +126,7 @@
 		  | _ => if c<>q andalso validChar(f,c) then putChar(f,c) else putCharRef(f,c)
 				   
 	    val f1 = putChar(f,q)
-	    val f2 = Vector.foldli putOne f1 (cv,0,NONE)
+            val f2 = Vector.foldli putOne f1 cv
 	    val f3 = putChar(f2,q)
 	 in f3
 	 end

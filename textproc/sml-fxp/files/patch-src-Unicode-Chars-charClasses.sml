diff -Naur src/Unicode/Chars/charClasses.sml.orig src/Unicode/Chars/charClasses.sml
--- src/Unicode/Chars/charClasses.sml.orig	2003-10-09 09:47:58.000000000 -0500
+++ src/Unicode/Chars/charClasses.sml	2003-10-17 13:49:08.000000000 -0500
@@ -91,7 +91,7 @@
       (*--------------------------------------------------------------------*)
       fun initialize(min,max) = 
 	 Array.array((Chars.toInt max-Chars.toInt min+1) div 32+1,0wx0):MutableClass
-      fun finalize arr = Array.extract(arr,0,NONE)
+      fun finalize arr = Array.vector arr
 	 
       (*--------------------------------------------------------------------*)
       (* add a single character to a CharClass.                             *)

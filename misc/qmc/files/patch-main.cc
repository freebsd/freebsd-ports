
$FreeBSD$

--- main.cc.orig	Mon Feb 24 00:41:46 2003
+++ main.cc	Mon Feb 24 00:43:25 2003
@@ -166,7 +166,7 @@
     var= new BOOL[anz];
 
     //number of possibilities
-    help=pow(2,anz);
+    help=pow((unsigned short)2,(unsigned short)anz);
 
     //create boolean array
     erg = new bool[help];
@@ -242,7 +242,7 @@
 
 
   //number of possibilty
-  help=pow(2,anz);
+  help=pow((unsigned short)2,(unsigned short)anz);
 
 
   //create boolean array

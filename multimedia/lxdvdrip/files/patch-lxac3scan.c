--- lxac3scan.c.orig	Tue Feb 22 20:56:28 2005
+++ lxac3scan.c	Wed Jul  6 18:36:10 2005
@@ -19,11 +19,11 @@
   FILE* fStdin;
   FILE* fStdout;
     
+  char ch=' '; 
+  
   fStdin = fopen ("/dev/stdin", "rb");
   fStdout = fopen ("/dev/stdout", "wb");
 
-  char ch=' '; 
-  
   // Schleife 1: Alles ueberspringen bis zum ersten sync word
   do {
     if (fread (&ch, 1, 1, fStdin) <= 0) break;

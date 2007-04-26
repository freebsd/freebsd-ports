--- ./src/triSurface/triSurface/interfaces/STL/readSTLASCII.L.orig	Sun Apr  8 18:39:23 2007
+++ ./src/triSurface/triSurface/interfaces/STL/readSTLASCII.L	Fri Apr 13 23:18:22 2007
@@ -166,7 +166,7 @@
     }
 
 <readSolidName>{string} {
-        word solidName(string::validate<word>(YYText()));
+        word solidName(Foam::string::validate<word>(YYText()));
         if (STLsolidNames.found(solidName))
         {
             region = STLsolidNames[solidName];

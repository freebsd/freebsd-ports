--- Lib/Slatec/Makefile.PL.orig	Mon Mar 29 00:20:18 2004
+++ Lib/Slatec/Makefile.PL	Mon Mar 29 00:19:57 2004
@@ -118,7 +118,7 @@
 ("
 
 slatec/$_\$(OBJ_EXT): slatec/$_.f 
-	$mycompiler -c -o slatec/$_\$(OBJ_EXT) $mycflags slatec/$_.f
+	$mycompiler -c -fPIC -o slatec/$_\$(OBJ_EXT) $mycflags slatec/$_.f
 " )} @slatecfiles;
  
 }

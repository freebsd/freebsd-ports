--- src/genrand.c.orig	1998-07-25 07:50:16 UTC
+++ src/genrand.c
@@ -31,7 +31,7 @@
 #include <sys/stat.h>
 #include "sysdep.h"
 
-void
+int
 main(const int argc, char* argv[])
 {
     FILE* file;
@@ -70,4 +70,5 @@ main(const int argc, char* argv[])
     }
 
     fclose(file);
+    return(0);
 }

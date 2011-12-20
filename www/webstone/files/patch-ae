--- genrand.c~	1998-07-25 09:50:16.000000000 +0200
+++ genrand.c	2011-12-20 19:16:38.086174883 +0100
@@ -31,7 +31,7 @@
 #include <sys/stat.h>
 #include "sysdep.h"
 
-void
+int
 main(const int argc, char* argv[])
 {
     FILE* file;
@@ -70,4 +70,5 @@
     }
 
     fclose(file);
+    return(0);
 }

--- setpath.c.orig
+++ setpath.c
@@ -15,6 +15,8 @@
 #include	"dir.H"
 #include	"misc.h"
 
+#include <string.h>
+
 
 BOOLEAN SetPath( DirInh, Pfad)
   DIRECTORY 	*DirInh;

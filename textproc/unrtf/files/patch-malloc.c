--- malloc.c.orig	Tue Mar 26 21:50:37 2002
+++ malloc.c	Tue Mar 26 21:52:14 2002
@@ -39,11 +39,7 @@
 #include <stdio.h>
 #include <string.h>
 
-#if AMIGA
 #include <stdlib.h>
-#else
-#include <malloc.h>
-#endif
 
 #include "error.h"
 

--- source/regexp.c.orig	Fri Mar 28 10:09:46 2003
+++ source/regexp.c	Fri Mar 28 10:10:13 2003
@@ -56,7 +56,7 @@
 
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include "regexp.h"

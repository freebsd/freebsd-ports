--- interp.c.orig
+++ interp.c
@@ -33,7 +33,7 @@
 #include <setjmp.h>
 #include <ctype.h>
 
-extern int errno;		/* set by math functions */
+#include <errno.h>
 
 #include "sc.h"
 
@@ -516,7 +516,7 @@
     mdays[1] = 28 + (yr%4 == 0);
 
     if (mo < 1 || mo > 12 || day < 1 || day > mdays[--mo] ||
-		yr > 1999 || yr < 1970) {
+		yr > 2099 || yr < 1970) {
 	scerror("@dts: invalid argument");
 	cellerror = CELLERROR;
 	return(0.0);

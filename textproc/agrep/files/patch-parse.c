
$FreeBSD$

--- parse.c.orig	Fri Jan 17 20:14:43 1992
+++ parse.c	Sun Jul 21 03:50:47 2002
@@ -3,6 +3,7 @@
    tree for that regular expression.				*/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "re.h"
 
 #define FALSE	0

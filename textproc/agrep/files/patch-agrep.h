
$FreeBSD$

--- agrep.h.orig	Fri Jan 17 20:15:13 1992
+++ agrep.h	Sun Jul 21 03:50:47 2002
@@ -1,10 +1,10 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <math.h>
 #include <ctype.h>
 #include "re.h"
 
-extern unsigned char *strcpy(), *strncpy(), *strcat();
-extern int strlen();
 #define CHAR	unsigned char
 #define MAXPAT 128
 #define MAXPATT 256

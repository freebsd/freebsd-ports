--- lib/expatls.c.orig	Tue Oct  9 13:28:19 2001
+++ lib/expatls.c	Tue Oct  9 13:28:07 2001
@@ -24,6 +24,7 @@
 
 /* expatls.c - DOM_DocumentLS
  */
+#include <sys/types.h>
 #include <limits.h>
 #include <ctype.h>
 #include <stdio.h>

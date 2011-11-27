--- relay/control.c.orig	1994-09-08 21:42:09.000000000 +0200
+++ relay/control.c	2011-05-12 15:38:44.000000000 +0200
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <ctype.h>
 #include <string.h>
 #include <errno.h>

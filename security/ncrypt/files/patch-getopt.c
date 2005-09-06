--- getopt.c.orig	Tue Aug 30 11:15:09 2005
+++ getopt.c	Tue Aug 30 11:15:23 2005
@@ -46,6 +46,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C

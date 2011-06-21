--- ./readhead.c.orig	2003-01-05 15:58:05.000000000 +0100
+++ ./readhead.c	2011-06-21 16:03:11.000000000 +0200
@@ -55,7 +55,7 @@
 /* Functions to read signature and headers                                    */
 /******************************************************************************/
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 
 #ifndef _WIN32

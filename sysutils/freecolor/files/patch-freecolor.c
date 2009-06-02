--- ./freecolor.c.orig	2009-05-31 08:48:43.000000000 +0100
+++ ./freecolor.c	2009-06-02 11:33:43.000000000 +0100
@@ -62,9 +62,6 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
-#ifndef NO_GETOPT
-#include <getopt.h>
-#endif
 #define BARLEN 35
 #define HEADERLEN 14
 #define VERSION "0.8.8"

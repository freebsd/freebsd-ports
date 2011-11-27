--- libc/fgetfln.c.orig	1993-03-09 07:22:54.000000000 +0100
+++ libc/fgetfln.c	2010-10-08 19:40:28.000000000 +0200
@@ -6,6 +6,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
+#include <string.h>
 #include <sys/types.h>
 #include <fgetfln.h>
 #include <hdbm.h>

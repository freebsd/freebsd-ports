diff -ru ../../work/nat10/nat.c ./nat.c
--- nat.c.orig	Sun Feb 16 19:18:04 1997
+++ nat.c	Sat Jun 14 23:10:07 2003
@@ -13,6 +13,7 @@
 #include <varargs.h>
 #endif
 #include "parse_ip.h"
+#include "includes.h"
 
 extern char *optarg;
 extern int optind;

--- decode.c.orig	1992-02-24 12:45:37.000000000 -0800
+++ decode.c	2007-08-23 15:38:55.000000000 -0700
@@ -19,4 +19,6 @@
 #include "cmd.h"
 
+static int cmd_search(char *, char *);
+
 /*
  * Command table is ordered roughly according to expected

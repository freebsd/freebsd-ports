--- ch.c	1992-02-24 12:45:37.000000000 -0800
+++ ../../ch.c	2007-08-23 15:35:14.000000000 -0700
@@ -7,4 +7,6 @@
 #include "less.h"
 
+static int ch_addbuf(int);
+
 public int file = -1;		/* File descriptor of the input file */
 

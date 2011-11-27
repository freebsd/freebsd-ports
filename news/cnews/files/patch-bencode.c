--- batch/bencode.c.orig	1991-11-04 19:16:50.000000000 +0100
+++ batch/bencode.c	2011-05-12 14:53:40.000000000 +0200
@@ -2,6 +2,7 @@
  * bencode [file]
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include "coder.h"
 #define MAXPERLINE 78		/* max chars/line */
 char *myname;

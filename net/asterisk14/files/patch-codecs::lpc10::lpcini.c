
$FreeBSD$

--- codecs/lpc10/lpcini.c.orig	Wed Feb 12 15:59:15 2003
+++ codecs/lpc10/lpcini.c	Fri Oct 17 12:13:04 2003
@@ -29,9 +29,9 @@
 	-lf2c -lm   (in that order)
 */
 
-#include "f2c.h"
+#include <stdlib.h>
 
-#include <malloc.h>
+#include "f2c.h"
 
 /* Common Block Declarations */
 

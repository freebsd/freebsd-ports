--- SRC/sp_coletree.c.orig	Fri Sep 26 08:22:05 2003
+++ SRC/sp_coletree.c	Thu Apr  1 20:29:10 2004
@@ -2,6 +2,9 @@
 /*  Elimination tree computation and layout routines */
 
 #include <stdio.h>
+#ifndef __STDC__
+#include <malloc.h>
+#endif
 #include <stdlib.h>
 #include "dsp_defs.h"
 

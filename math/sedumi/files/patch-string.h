--- iswnbr.c~	2008-10-06 10:47:34.000000000 +0900
+++ iswnbr.c	2008-10-06 10:51:42.000000000 +0900
@@ -39,6 +39,7 @@
 
 #include <math.h>
 #include <stdlib.h>
+#include <string.h>
 #include "mex.h"
 
 #define	DELTA_OUT myplhs[0]
--- quadadd.c~	2008-10-06 10:47:34.000000000 +0900
+++ quadadd.c	2008-10-06 10:51:34.000000000 +0900
@@ -39,6 +39,7 @@
  */
 #include <math.h>
 #include "mex.h"
+#include <string.h>
 #include "blksdp.h"
 
 #define ZHI_OUT myplhs[0]
--- vecsym.c~	2008-10-06 10:47:34.000000000 +0900
+++ vecsym.c	2008-10-06 10:51:18.000000000 +0900
@@ -39,6 +39,7 @@
 
 #include <math.h>
 #include "mex.h"
+#include <string.h>
 #include "blksdp.h"
 
 #define Y_OUT plhs[0]
--- bwblkslv.c~	2008-10-06 10:47:33.000000000 +0900
+++ bwblkslv.c	2008-10-06 10:51:12.000000000 +0900
@@ -42,6 +42,7 @@
 */
 
 #include "mex.h"
+#include <string.h>
 #include "blksdp.h"
 
 #define Y_OUT plhs[0]

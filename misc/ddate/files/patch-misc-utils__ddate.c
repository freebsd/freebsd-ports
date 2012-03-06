--- ./misc-utils/ddate.c.orig	2012-03-06 16:45:33.000000000 +0100
+++ ./misc-utils/ddate.c	2012-03-06 16:46:18.000000000 +0100
@@ -62,8 +62,9 @@
 #include <time.h>
 #include <stdio.h>
 
-#include "nls.h"
-#include "c.h"
+#include "../include/nls.h"
+#include "../include/c.h"
+#include "../config.h"
 
 #ifndef __GNUC__
 #define inline /* foo */

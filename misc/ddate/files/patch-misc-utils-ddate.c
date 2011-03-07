--- ./misc-utils/ddate.c.orig	2010-11-30 11:26:31.000000000 +0100
+++ ./misc-utils/ddate.c	2011-03-07 11:54:40.000000000 +0100
@@ -61,7 +61,8 @@
 #include <string.h>
 #include <time.h>
 #include <stdio.h>
-#include "nls.h"
+#include "../include/nls.h"
+#include "../config.h"
 
 #ifndef __GNUC__
 #define inline /* foo */

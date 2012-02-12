--- tests/cutest.c.orig	2012-02-11 05:08:50.706340443 -0500
+++ tests/cutest.c	2012-02-11 05:09:03.816423151 -0500
@@ -34,6 +34,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <math.h>
+#include <sys/wait.h>
 
 #include "cutest.h"
 #include "memory.h"

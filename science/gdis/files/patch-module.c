--- module.c.orig	Tue Jun 15 16:05:21 2004
+++ module.c	Mon Jul  5 05:01:06 2004
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <gmodule.h>
 
 #include "gdis.h"

--- src/xitk/snapshot.c.orig	Fri Oct 19 16:41:20 2001
+++ src/xitk/snapshot.c	Fri Oct 19 16:41:46 2001
@@ -48,7 +48,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <alloca.h>
+#include <stdlib.h>
 #include <pthread.h>
 
 #include "xitk.h"

--- mplayerxp/libao2/ao_null.c.orig	2007-12-02 18:19:44.000000000 +0900
+++ mplayerxp/libao2/ao_null.c	2009-01-07 18:28:00.000000000 +0900
@@ -3,6 +3,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <limits.h>
+#include <sys/types.h>
 #include <sys/time.h>
 
 #include "config.h"

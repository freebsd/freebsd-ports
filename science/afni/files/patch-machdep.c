--- machdep.c.orig	2020-04-18 13:02:47 UTC
+++ machdep.c
@@ -2,7 +2,11 @@
 #include "mrilib.h"
 
 #ifndef DARWIN
-# include <malloc.h>
+# ifdef __FreeBSD__
+#  include <stdlib.h>
+# else
+#  include <malloc.h>
+# endif
 #endif
 
 #include <unistd.h>

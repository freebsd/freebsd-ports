--- xo/stats.h.orig	Thu Dec  9 10:02:22 2004
+++ xo/stats.h	Thu Dec  9 10:03:35 2004
@@ -39,6 +39,8 @@
   /* ----- Includes */
 
 #include <sys/times.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #if defined (HAVE_MEMORY_H)
 # include <memory.h>

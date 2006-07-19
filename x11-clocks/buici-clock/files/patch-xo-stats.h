--- xo/stats.h.orig	Wed Jul 12 02:06:02 2006
+++ xo/stats.h	Wed Jul 12 02:06:18 2006
@@ -39,6 +39,8 @@
   /* ----- Includes */
 
 #include <sys/times.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #if defined (HAVE_MEMORY_H)
 # include <memory.h>

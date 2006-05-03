--- util/seconds.c.orig	Mon May  1 16:41:39 2006
+++ util/seconds.c	Mon May  1 16:42:30 2006
@@ -2,6 +2,7 @@
  * at Sandia National Laboratories under US Department of Energy        *
  * contract DE-AC04-76DP00789 and is copyrighted by Sandia Corporation. */
 
+#include   <sys/types.h>
 #include   <sys/time.h>
 #include   <sys/resource.h>
 

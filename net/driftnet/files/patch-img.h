$FreeBSD$

--- img.h.orig	Tue Sep 11 11:34:56 2001
+++ img.h	Fri Mar  1 00:01:34 2002
@@ -12,7 +12,7 @@
 #ifndef __IMG_H_ /* include guard */
 #define __IMG_H_
 
-#include <stdint.h>
+#include <sys/types.h>
 #include <stdio.h>
 
 typedef uint8_t chan;

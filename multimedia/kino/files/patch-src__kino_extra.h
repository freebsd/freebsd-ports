--- src/kino_extra.h.orig	Thu Apr 13 08:07:40 2006
+++ src/kino_extra.h	Tue Jul 18 23:09:33 2006
@@ -20,7 +20,8 @@
 #ifndef _KINO_EXTRA_H_
 #define _KINO_EXTRA_H_
 
-#include <stdint.h>
+// #include <stdint.h>
+#include <sys/types.h>
 #include <gtk/gtk.h>
 
 // This is mandatory for plug-ins to be able to access the functionality here

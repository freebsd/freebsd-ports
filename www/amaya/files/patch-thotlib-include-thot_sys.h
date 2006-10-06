--- ../thotlib/include/thot_sys.h.orig	Wed Mar 22 10:50:05 2006
+++ ../thotlib/include/thot_sys.h	Tue Sep  5 15:17:44 2006
@@ -252,9 +252,11 @@
 #define MAX_BYTES 6
 
 /* we encourage using "long" to store pointer values, never use "int" ! */
+#ifndef _BSD
 #ifndef __intptr_t_defined
 #define __intptr_t_defined
 typedef           long   intptr_t;
+#endif
 #endif
 
 #endif /* THOT_SYS_H */

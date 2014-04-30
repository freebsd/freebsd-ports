--- screen.c
+++ screen.c
@@ -50,7 +50,7 @@
 
 #include "config.h"
 
-#ifdef SVR4
+#if defined(SVR4) && !defined(__FreeBSD__)
 # include <sys/stropts.h>
 #endif
 

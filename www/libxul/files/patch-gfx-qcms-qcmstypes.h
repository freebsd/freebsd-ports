--- gfx/qcms/qcmstypes.h.orig	2010-11-22 12:01:36.000000000 +0100
+++ gfx/qcms/qcmstypes.h	2010-11-22 12:02:42.000000000 +0100
@@ -25,7 +25,7 @@
 #ifdef __OS2__
 /* OS/2's stdlib typdefs uintptr_t. So we'll just include that so we don't collide */
 #include <stdlib.h>
-#elif !defined(__intptr_t_defined) && !defined(_UINTPTR_T_DEFINED)
+#elif !defined(__intptr_t_defined) && !defined(_INTPTR_T_DECLARED) 
 typedef PRUptrdiff uintptr_t;
 #endif
 #endif

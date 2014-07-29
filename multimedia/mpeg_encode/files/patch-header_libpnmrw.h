--- headers/libpnmrw.h.orig	Wed Aug  9 11:17:41 1995
+++ headers/libpnmrw.h	Tue Jul 23 17:06:15 2002
@@ -20,7 +20,7 @@
 ** that point here, feel free to tweak or remove these declarations.
 */
 #include <malloc.h>
-#if !defined(sco)  &&  !defined(sgi) && !defined(IRIX)
+#if !defined(sco)  &&  !defined(sgi) && !defined(IRIX) && !defined(__FreeBSD__)
 extern char* malloc();
 #endif
 /* End of configurable definitions. */

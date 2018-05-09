--- shared/types.h.orig	2008-07-11 23:21:43 UTC
+++ shared/types.h
@@ -39,7 +39,7 @@
  *
  **************************************************************************** */
 
-#if defined(__ppc__) && defined(__APPLE__)
+#if defined(__ppc__) && defined(__APPLE__) || defined (__FreeBSD__)
 #include <sys/types.h>
 
 typedef int8_t s8;

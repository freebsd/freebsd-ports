--- ./src/util/sys_defs.h.orig	Wed Aug 25 06:15:02 2004
+++ ./src/util/sys_defs.h	Wed Aug 25 06:15:18 2004
@@ -24,7 +24,7 @@
   * 4.4BSD and close derivatives.
   */
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
-    || defined(FREEBSD5) \
+    || defined(FREEBSD5) || defined(FREEBSD6) \
     || defined(BSDI2) || defined(BSDI3) || defined(BSDI4) \
     || defined(OPENBSD2) || defined(OPENBSD3) \
     || defined(NETBSD1) || defined(NETBSD2) \

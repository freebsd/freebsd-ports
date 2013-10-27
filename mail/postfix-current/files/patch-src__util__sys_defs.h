--- src/util/sys_defs.h.orig	2013-10-27 02:03:59.000000000 +0000
+++ src/util/sys_defs.h	2013-10-27 02:04:50.000000000 +0000
@@ -25,7 +25,8 @@
   */
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
     || defined(FREEBSD5) || defined(FREEBSD6) || defined(FREEBSD7) \
-    || defined(FREEBSD8) || defined(FREEBSD9) \
+    || defined(FREEBSD8) || defined(FREEBSD9) || defined(FREEBSD10) \
+    || defined(FREEBSD11) \
     || defined(BSDI2) || defined(BSDI3) || defined(BSDI4) \
     || defined(OPENBSD2) || defined(OPENBSD3) || defined(OPENBSD4) \
     || defined(OPENBSD5) \

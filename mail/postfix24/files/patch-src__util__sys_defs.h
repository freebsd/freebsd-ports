--- src/util/sys_defs.h.orig	2010-04-04 17:19:32.000000000 -0400
+++ src/util/sys_defs.h	2010-04-04 17:23:49.000000000 -0400
@@ -25,7 +25,7 @@
   */
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
     || defined(FREEBSD5) || defined(FREEBSD6) || defined(FREEBSD7) \
-    || defined(FREEBSD8) \
+    || defined(FREEBSD8) || defined(FREEBSD9) \
     || defined(BSDI2) || defined(BSDI3) || defined(BSDI4) \
     || defined(OPENBSD2) || defined(OPENBSD3) || defined(OPENBSD4) \
     || defined(NETBSD1) || defined(NETBSD2) || defined(NETBSD3) \
@@ -98,7 +98,7 @@
 #define SOCKOPT_SIZE	socklen_t
 #endif
 
-#if __FreeBSD_version >= 800107		/* safe; don't believe the experts */
+#if (__FreeBSD_version >= 702104 && __FreeBSD_version < 800000) || (__FreeBSD_version >= 800099)
 #define HAS_CLOSEFROM
 #endif
 

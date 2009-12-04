--- src/util/sys_defs.h.orig	2009-12-03 22:30:03.000000000 -0200
+++ src/util/sys_defs.h	2009-12-03 22:31:51.000000000 -0200
@@ -25,7 +25,7 @@
   */
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
     || defined(FREEBSD5) || defined(FREEBSD6) || defined(FREEBSD7) \
-    || defined(FREEBSD8) \
+    || defined(FREEBSD8) || defined(FREEBSD9) \
     || defined(BSDI2) || defined(BSDI3) || defined(BSDI4) \
     || defined(OPENBSD2) || defined(OPENBSD3) || defined(OPENBSD4) \
     || defined(NETBSD1) || defined(NETBSD2) || defined(NETBSD3) \
@@ -111,7 +111,8 @@
 #define HAS_DUPLEX_PIPE			/* 4.1 breaks with kqueue(2) */
 #endif
 
-#if __FreeBSD_version >= 800107		/* safe; don't believe the experts */
+#if (__FreeBSD_version >= 702104 && __FreeBSD_version <= 800000) \
+	|| __FreeBSD_version >= 800100
 #define HAS_CLOSEFROM
 #endif
 

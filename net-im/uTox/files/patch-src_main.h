--- src/main.h.orig	2016-05-13 18:05:27.586256000 +0300
+++ src/main.h	2016-05-13 18:06:21.738883000 +0300
@@ -74,7 +74,7 @@
 #define volatile(x) (*((volatile typeof(x)*)&x))
 #endif */
 
-#ifndef __OBJC__
+#if !defined(__OBJC__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 #define volatile(x) (x)
 #endif
 /* UTOX_SCALE is used as the default so that we have a lot of options for scale size.

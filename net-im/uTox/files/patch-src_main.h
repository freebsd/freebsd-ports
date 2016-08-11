--- src/main.h.orig	2016-07-26 23:53:18 UTC
+++ src/main.h
@@ -45,7 +45,7 @@
 #define volatile(x) (*((volatile typeof(x)*)&x))
 #endif */
 
-#ifndef __OBJC__
+#if !defined(__OBJC__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 #define volatile(x) (x)
 #endif
 /* UTOX_SCALE is used as the default so that we have a lot of options for scale size.

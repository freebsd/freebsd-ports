--- src/main.h.orig	2016-12-21 09:12:44 UTC
+++ src/main.h
@@ -80,8 +80,8 @@
 #define volatile(x) (*((volatile typeof(x)*)&x))
 #endif */
 
-#ifndef __OBJC__
-#define volatile(x)(x)
+#if !defined(__OBJC__) || defined(__NetBSD__) || defined(__FreeBSD__)
+#define volatile(x) x
 #endif
 
 #define SCALE(x) (((int)((ui_scale / 10.0) * ((double)x))) ?: 1)

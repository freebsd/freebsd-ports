--- src/core/common.h.orig	Fri Nov 28 22:54:22 2003
+++ src/core/common.h	Sat Dec 27 18:47:34 2003
@@ -75,19 +75,23 @@
 typedef signed char         s8;
 typedef signed short        s16;
 typedef signed int          s32;
+#ifndef __FreeBSD__
 #ifdef _WIN32
 typedef __int64             s64;
 #else
 typedef signed long long    s64;
 #endif
+#endif
 
 typedef unsigned char       u8;
 typedef unsigned short      u16;
 typedef unsigned int        u32;
+#ifndef __FreeBSD__
 #ifdef _WIN32
 typedef unsigned __int64    u64;
 #else
 typedef unsigned long long  u64;
+#endif
 #endif
 
 // Byte type

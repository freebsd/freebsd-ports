--- communicate.h        Fri Sep 26 04:07:11 2003
+++ communicate.h     Thu Mar 11 12:51:34 2004
@@ -38,7 +38,9 @@
 #if defined(sun) || __GLIBC__ > 2 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 1)
 #define STAT64_SUPPORT
 #else
+#if !defined(__FreeBSD__)
 #warning Not using stat64 support
+#endif
 /* if glibc is 2.0 or older, undefine these again */
 #undef STAT64_SUPPORT
 #undef _LARGEFILE64_SOURCE 

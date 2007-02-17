--- include/xrnMman.h.orig	2005-05-10 08:18:10.000000000 +0000
+++ include/xrnMman.h	2007-01-24 15:12:15.000000000 +0000
@@ -37,8 +37,11 @@
 
 typedef X2C_INT32 INT32;
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#else
 extern X2C_ADDRESS mmap(X2C_ADDRESS, X2C_CARD32, X2C_CARD32, X2C_CARD32,
                 X2C_INT32, X2C_CARD32);
+#endif
 
 extern X2C_INT32 munmap(X2C_ADDRESS, X2C_CARD32);
 

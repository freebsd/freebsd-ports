--- src/include/sysdep.h.orig	2007-10-17 09:51:14.000000000 +0200
+++ src/include/sysdep.h	2007-10-17 09:50:32.000000000 +0200
@@ -96,10 +96,6 @@ size_t strlcat (char *, const char *, si
 #define _PASSWORD_LEN	128
 #endif
 
-#if defined(__FreeBSD__)
-typedef int32_t in_addr_t;
-#endif /* __FreeBSD__ */
-
 int init_socket ();
 
 #endif /* SYSDEP */

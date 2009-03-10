--- ./libs/libmyth/compat.h.orig	2008-02-18 02:35:01.000000000 -0500
+++ ./libs/libmyth/compat.h	2009-02-23 09:59:26.000000000 -0500
@@ -273,7 +273,7 @@
 
 // Libdvdnav now uses off64_t lseek64(), which Darwin doesn't have.
 // Luckily, its lseek() is already 64bit compatible
-#ifdef CONFIG_DARWIN
+#if defined(CONFIG_DARWIN) || defined(__FreeBSD__)
     typedef off_t off64_t;
     #define lseek64(f,o,w) lseek(f,o,w)
 #endif

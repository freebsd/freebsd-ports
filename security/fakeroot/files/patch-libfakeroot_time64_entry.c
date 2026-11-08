--- libfakeroot_time64_entry.c.orig	2026-08-28 12:06:14 UTC
+++ libfakeroot_time64_entry.c
@@ -64,7 +64,7 @@
     }
   #endif
 
-    #ifndef NO_WRAP_LSTAT64_SYMBOL
+    #if defined(WRAP_LSTAT64) && !defined(NO_WRAP_LSTAT64_SYMBOL)
     extern int WRAP_LSTAT64 LSTAT64_ARG (int ver, const char *file_name, void *st);
 
     /* glibc exports both lstat64 and __xstat64 */
@@ -72,7 +72,7 @@
        return WRAP_LSTAT64 LSTAT64_ARG(_STAT_VER, file_name, st);
     }
     #endif
-    #ifndef NO_WRAP_STAT64_SYMBOL
+    #if defined(WRAP_STAT64) && !defined(NO_WRAP_STAT64_SYMBOL)
     extern int WRAP_STAT64 STAT64_ARG(int ver, const char *file_name, void *st);
 
     /* glibc exports both stat64 and __xstat64 */
@@ -80,7 +80,7 @@
        return WRAP_STAT64 STAT64_ARG(_STAT_VER, file_name, st);
     }
     #endif
-    #ifndef NO_WRAP_FSTAT64_SYMBOL
+    #if defined(WRAP_FSTAT64) && !defined(NO_WRAP_FSTAT64_SYMBOL)
     extern int WRAP_FSTAT64 FSTAT64_ARG(int ver, int fd, void *st);
 
     /* glibc exports both fstat64 and __fxstat64 */
@@ -89,7 +89,7 @@
     }
     #endif
 
-    #if defined(HAVE_FSTATAT) && !defined(NO_WRAP_FSTATAT64_SYMBOL)
+    #if defined(HAVE_FSTATAT) && defined(WRAP_FSTATAT64) && !defined(NO_WRAP_FSTATAT64_SYMBOL)
     extern int WRAP_FSTATAT64 FSTATAT64_ARG(int ver, int dir_fd, const char *path, void *st, int flags);
 
     /* glibc exports both fstatat64 and __fxstatat64 */


$FreeBSD$

--- common/basis_types.h.orig
+++ common/basis_types.h
@@ -251,12 +251,10 @@
    else \
       variable = pthread_getspecific(key)
 
-#if !defined(FREEBSD)
 #define HAS_GETPWNAM_R
 #define HAS_GETGRNAM_R
 #define HAS_GETPWUID_R
 #define HAS_GETGRGID_R
-#endif
 
 #define HAS_LOCALTIME_R
 #define HAS_CTIME_R

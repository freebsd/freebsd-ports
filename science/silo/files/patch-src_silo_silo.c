--- src/silo/silo.c.orig	2014-10-14 00:22:33 UTC
+++ src/silo/silo.c
@@ -226,12 +226,8 @@ typedef struct db_silo_stat_t {
 #ifndef SIZEOF_OFF64_T
 #error missing definition for SIZEOF_OFF64_T in silo_private.h
 #else
-#if SIZEOF_OFF64_T > 4
-    struct stat64 s;
-#else
     struct stat s;
 #endif
-#endif
 #ifdef _WIN32
     DWORD fileindexlo;
     DWORD fileindexhi;
@@ -2283,11 +2279,7 @@ db_silo_stat_one_file(const char *name, 
     errno = 0;
     memset(&(statbuf->s), 0, sizeof(statbuf->s));
 
-#if SIZEOF_OFF64_T > 4
-    retval = stat64(name, &(statbuf->s));
-#else
     retval = stat(name, &(statbuf->s));
-#endif /* #if SIZEOF_OFF64_T > 4 */
 
 #ifdef _WIN32
     if (retval == 0)
@@ -4225,11 +4217,7 @@ DBOpenReal(const char *name, int type, i
                 /********************************/
                 /* System level error occured.  */
                 /********************************/
-#if SIZEOF_OFF64_T > 4
-                printf("stat64() failed with error: ");
-#else
                 printf("stat() failed with error: ");
-#endif
                 switch (errno)
                 {
                   case EACCES:       printf("EACCES\n");       break;

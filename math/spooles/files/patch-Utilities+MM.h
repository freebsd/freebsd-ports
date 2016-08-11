--- Utilities/MM.h.orig	1998-05-30 22:45:00 UTC
+++ Utilities/MM.h
@@ -30,21 +30,21 @@
 */
 #define ALLOCATE(ptr, type, count) \
 if ( (count) > 0 ) { \
-   if ( (ptr = (type *)malloc((unsigned long)((count)*sizeof(type)))) \
+   if ( (ptr = malloc((unsigned long)(count)*sizeof(type))) \
         == NULL ) {\
       fprintf(stderr, \
-              "\n ALLOCATE failure : bytes %d, line %d, file %s", \
+              "\n ALLOCATE failure : bytes %lu, line %d, file %s", \
               (count)*sizeof(type), __LINE__, __FILE__) ; \
       exit(-1) ; } \
    else if ( MEMORY_DEBUG > 0 ) { \
       fprintf(stderr, \
-              "\n ALLOCATE : address %p, bytes %d, line %d, file %s", \
+              "\n ALLOCATE : address %p, bytes %lu, line %d, file %s", \
               ptr, (count)*sizeof(type), __LINE__, __FILE__) ; } } \
 else if ( (count) == 0 ) { \
    ptr = NULL ; } \
 else { \
    fprintf(stderr, \
-           "\n ALLOCATE error : bytes %d, line %d, file %s", \
+           "\n ALLOCATE error : bytes %lu, line %d, file %s", \
            (count)*sizeof(type), __LINE__, __FILE__) ; \
    exit(-1) ; }
 /*

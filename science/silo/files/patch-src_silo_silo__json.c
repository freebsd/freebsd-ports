--- src/silo/silo_json.c.orig	2025-11-21 05:30:59 UTC
+++ src/silo/silo_json.c
@@ -446,11 +446,7 @@ json_object_from_binary_file(char const *filename)
 #ifndef SIZEOF_OFF64_T
 #error missing definition for SIZEOF_OFF64_T in silo_private.h
 #else
-#if SIZEOF_OFF64_T > 4
-    struct stat64 s;
-#else
     struct stat s;
-#endif
 #endif
 
     errno = 0;

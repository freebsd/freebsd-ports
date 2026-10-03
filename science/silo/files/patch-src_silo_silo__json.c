-- do not use stat64

--- src/silo/silo_json.c.orig	2026-07-28 07:31:59 UTC
+++ src/silo/silo_json.c
@@ -423,11 +423,7 @@ json_object_from_binary_file(char const *filename)
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

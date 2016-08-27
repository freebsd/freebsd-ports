--- src/silo/silo_json.c.orig	2014-10-14 00:22:33 UTC
+++ src/silo/silo_json.c
@@ -441,12 +441,8 @@ json_object_from_binary_file(char const 
 #ifndef SIZEOF_OFF64_T
 #error missing definition for SIZEOF_OFF64_T in silo_private.h
 #else
-#if SIZEOF_OFF64_T > 4
-    struct stat64 s;
-#else
     struct stat s;
 #endif
-#endif
 
     errno = 0;
     memset(&s, 0, sizeof(s));

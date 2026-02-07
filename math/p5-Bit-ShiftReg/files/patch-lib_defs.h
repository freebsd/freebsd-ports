--- ./lib_defs.h.orig	2013-10-05 00:19:24.238806604 +0400
+++ ./lib_defs.h	2013-10-05 00:19:56.892159090 +0400
@@ -62,7 +62,7 @@
 #undef  TRUE
 #define TRUE        (0==0)
 
-typedef enum { false = FALSE , true = TRUE } boolean;
+typedef enum { _false = FALSE , _true = TRUE } boolean;
 
 #define blockdef(name,size)         unsigned char name[size]
 #define blocktypedef(name,size)     typedef unsigned char name[size]

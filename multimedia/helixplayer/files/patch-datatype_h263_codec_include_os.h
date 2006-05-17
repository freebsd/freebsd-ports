--- datatype/h263/codec/include/os.h.orig	Sun Jul 25 04:27:00 2004
+++ datatype/h263/codec/include/os.h	Sun Jul 25 04:29:57 2004
@@ -98,8 +98,6 @@
 
 #define strcmpi strcasecmp
 #define _fmemset memset
-#define min(a,b) (((a) < (b) ? (a) : (b)))
-#define max(a,b) (((a) > (b) ? (a) : (b)))
 
 #define TRACE0
 

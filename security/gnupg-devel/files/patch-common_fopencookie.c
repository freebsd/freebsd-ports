--- common/fopencookie.c.orig	Mon May  3 18:14:56 2004
+++ common/fopencookie.c	Mon May  3 18:15:24 2004
@@ -26,6 +26,15 @@
 
 #include "util.h"
 
+typedef struct
+{
+  ssize_t (*read)(void*,char*,size_t);
+  ssize_t (*write)(void*,const char*,size_t);
+  int (*seek)(void*,off_t*,int);
+  int (*close)(void*);
+} _IO_cookie_io_functions_t;
+typedef _IO_cookie_io_functions_t cookie_io_functions_t;
+
 FILE * 
 fopencookie (void *cookie, const char *opentype,
              cookie_io_functions_t funclist)

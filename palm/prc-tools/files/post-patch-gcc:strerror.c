--- libiberty/strerror.c.orig2	Fri Feb  6 19:04:47 2004
+++ libiberty/strerror.c	Fri Feb  6 19:04:54 2004
@@ -13,7 +13,6 @@
    incompatible with our later declaration, perhaps by using const
    attributes.  So we hide the declaration in errno.h (if any) using a
    macro. */
-#define sys_nerr sys_nerr__
 #define sys_errlist sys_errlist__
 #endif
 
@@ -21,7 +20,6 @@
 #include <errno.h>
 
 #ifdef HAVE_SYS_ERRLIST
-#undef sys_nerr
 #undef sys_errlist
 #endif
 

--- get-edid/classic.c.orig	2015-04-29 01:08:34 UTC
+++ get-edid/classic.c
@@ -1,12 +1,12 @@
 /* (c) 2000,2001,2002 John Fremlin */
 /* (c) 2010,2011 Matthew Kern */
 #ifdef CLASSICBUILD
+#include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include <string.h>
 #include <sys/types.h>
-#include <sys/io.h>
 #include <unistd.h>
 
 #include <libx86.h>
@@ -26,7 +26,7 @@ typedef byte* real_ptr;
 #define dosmemput(buffer,length,offset) memcpy(offset,buffer,length)
 
 #define display(...) if (quiet == 0) { fprintf(stderr, __VA_ARGS__); }
-int quiet;
+extern int quiet;
 
 real_ptr far_ptr_to_real_ptr( uint32 farptr )
 {
@@ -135,8 +135,17 @@ classicmain( unsigned contr, int qit )
       return 10;
     }
   
+#if defined(__linux__)
   ioperm(0, 0x400 , 1);
   iopl(3);
+#elif defined(__FreeBSD__)
+#define DEV_IO_PATH "/dev/io"
+  if (open(DEV_IO_PATH, O_RDONLY) < 0) {
+    display("%s(): failed to open %s\n", __func__, DEV_IO_PATH);
+    return 11;
+  }
+#undef DEV_IO_PATH
+#endif
   
 
   /*if ( argc == 1 )

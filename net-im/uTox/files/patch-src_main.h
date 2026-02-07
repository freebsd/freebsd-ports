Fix build on arm

In file included from src/main.c:9:
In file included from src/native/main.h:16:
In file included from src/native/../xlib/main.h:18:
In file included from /usr/local/include/X11/extensions/Xrender.h:28:
In file included from /usr/local/include/X11/Xlib.h:38:
In file included from /usr/include/sys/types.h:46:
/usr/include/machine/endian.h:68:20: error: too many arguments provided to function-like macro
invocation
                         : "=&r" (ret), "+r" (x));
                                        ^
src/main.h:30:9: note: macro 'volatile' defined here
#define volatile(x)(x)
        ^

--- src/main.h.orig	2020-02-01 23:37:59 UTC
+++ src/main.h
@@ -26,10 +26,6 @@
 #define MAIN_WIDTH 750
 #define MAIN_HEIGHT 500
 
-#ifndef __OBJC__
-#define volatile(x)(x)
-#endif
-
 /* Support for large files. */
 #define _LARGEFILE_SOURCE
 #define _FILE_OFFSET_BITS 64

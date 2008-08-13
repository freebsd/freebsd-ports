--- libntfs/device_io.c.orig	2007-09-26 15:28:34.000000000 -0300
+++ libntfs/device_io.c	2008-08-10 20:27:34.000000000 -0300
@@ -28,11 +28,6 @@
 /* On Cygwin; use Win32 low level device operations. */
 #include "win32_io.c"
 
-#elif defined(__FreeBSD__)
-
-/* On FreeBSD; need to use sector aligned i/o. */
-#include "freebsd_io.c"
-
 #else
 
 /*

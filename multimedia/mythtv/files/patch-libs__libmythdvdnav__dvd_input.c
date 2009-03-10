--- ./libs/libmythdvdnav/dvd_input.c.orig	2008-01-27 14:27:40.000000000 -0500
+++ ./libs/libmythdvdnav/dvd_input.c	2009-02-23 09:59:26.000000000 -0500
@@ -27,6 +27,9 @@
 #include "dvd_reader.h"
 #include "dvd_input.h"
 
+#if defined(__FreeBSD__)
+#define lseek64 lseek
+#endif
 
 /* The function pointers that is the exported interface of this file. */
 dvd_input_t (*dvdinput_open)  (const char *);

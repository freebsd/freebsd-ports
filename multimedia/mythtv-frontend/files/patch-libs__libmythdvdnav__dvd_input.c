--- ./libs/libmythdvdnav/dvd_input.c.orig	2008-01-27 14:27:40.000000000 -0500
+++ ./libs/libmythdvdnav/dvd_input.c	2009-04-22 21:05:20.000000000 -0400
@@ -24,6 +24,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 
+#define off64_t off_t
+#define lseek64 lseek
+
 #include "dvd_reader.h"
 #include "dvd_input.h"
 

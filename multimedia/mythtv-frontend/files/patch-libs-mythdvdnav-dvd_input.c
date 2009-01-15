--- libs/libmythdvdnav/dvd_input.c	2008-09-14 22:40:08.000000000 +0200
+++ libs/libmythdvdnav/dvd_input.c	2008-09-14 22:40:22.000000000 +0200
@@ -24,6 +24,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 
+#define off64_t off_t
+#define lseek64 lseek
+
 #include "dvd_reader.h"
 #include "dvd_input.h"
 

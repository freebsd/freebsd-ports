--- wizd_http.c.orig	2008-07-02 12:30:10.000000000 +0900
+++ wizd_http.c	2008-07-02 13:12:25.000000000 +0900
@@ -23,7 +23,9 @@
 #include <dirent.h>
 #include <fcntl.h>
 #include <libgen.h>
+#ifdef __CYGWIN32__
 #include <sys/cygwin.h>
+#endif
 
 #include "wizd.h"
 #include "wizd_skin.h"
@@ -1072,7 +1074,6 @@
 {
 	struct stat send_filestat;
 	int result;
-	int len;
 
 	unsigned char	file_extension[16];
 

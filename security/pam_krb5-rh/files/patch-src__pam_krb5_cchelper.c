--- ./src/pam_krb5_cchelper.c.orig	2012-12-14 22:27:50.000000000 -0500
+++ ./src/pam_krb5_cchelper.c	2012-12-14 22:28:00.000000000 -0500
@@ -34,6 +34,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/syslimits.h>
 #include <dirent.h>
 #include <errno.h>
 #include <fcntl.h>

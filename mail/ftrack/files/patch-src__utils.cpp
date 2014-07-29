--- src/utils.cpp.orig Tue May 16 22:33:14 2000
+++ src/utils.cpp  Tue Jun 27 20:57:09 2000
@@ -22,6 +22,7 @@
 #include <ctype.h>
 #ifdef __FreeBSD__
 #   include <stdlib.h>
+#   include <sys/syslimits.h>
 #else
 #   include <malloc.h>
 #endif
@@ -144,7 +145,7 @@
 // Open file and create path if need.
 char *tmt;
 char Buff[1024];
-   umask(0);
+   umask(022);
    strcpy(Buff,Name);
    tmt = strrchr(Buff,PATHDELIMC);
    if (tmt != NULL) {

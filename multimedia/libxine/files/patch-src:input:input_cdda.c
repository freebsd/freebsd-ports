--- src/input/input_cdda.c.orig	Sun Dec 11 03:34:00 2005
+++ src/input/input_cdda.c	Sun Dec 11 03:34:07 2005
@@ -32,7 +32,7 @@
 #include <unistd.h>
 
 #include <sys/types.h>
-#ifdef SYS_PARAM_H
+#ifdef HAVE_SYS_PARAM_H
 #include <sys/param.h>
 #endif
 #ifdef HAVE_DIRENT_H

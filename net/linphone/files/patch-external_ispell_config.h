--- external/ispell/config.h.orig	2025-12-26 16:36:36 UTC
+++ external/ispell/config.h
@@ -228,7 +228,7 @@
 #include <sys/param.h>
 #include <sys/types.h>
 #ifndef USG
-#include <sys/dir.h>
+/* #include <sys/dir.h> */
 #endif /* USG */
 
 #ifndef TERMIOS

--- tests/test-parser.c.orig	2011-08-09 02:23:26 UTC
+++ tests/test-parser.c
@@ -30,6 +30,7 @@
 #include <fcntl.h>
 #include <time.h>
 
+#include <config.h>
 #include <gmime/gmime.h>
 
 #if !defined (G_OS_WIN32) || defined (__MINGW32__)

--- tests/test-parser.c.orig	Mon Feb 12 15:48:38 2007
+++ tests/test-parser.c	Mon Feb 12 15:49:14 2007
@@ -26,6 +26,7 @@
 #include <fcntl.h>
 #include <time.h>
 
+#include <config.h>
 #include <gmime/gmime.h>
 
 #ifndef G_OS_WIN32

--- tests/test-mbox.c.orig	Mon Feb 12 15:48:22 2007
+++ tests/test-mbox.c	Mon Feb 12 15:48:54 2007
@@ -26,6 +26,7 @@
 #include <fcntl.h>
 #include <time.h>
 
+#include <config.h>
 #include <gmime/gmime.h>
 
 #ifndef G_OS_WIN32

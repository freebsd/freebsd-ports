--- tests/test-mime.c.orig	Mon Feb 12 15:48:32 2007
+++ tests/test-mime.c	Mon Feb 12 15:49:04 2007
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <string.h>
 
+#include <config.h>
 #include <gmime/gmime.h>
 
 #ifndef G_OS_WIN32

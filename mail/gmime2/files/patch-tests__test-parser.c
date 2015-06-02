--- tests/test-parser.c.orig	2011-03-07 18:09:21 UTC
+++ tests/test-parser.c
@@ -30,6 +30,7 @@
 #include <fcntl.h>
 #include <time.h>
 
+#include <config.h>
 #include <gmime/gmime.h>
 
 #ifndef G_OS_WIN32

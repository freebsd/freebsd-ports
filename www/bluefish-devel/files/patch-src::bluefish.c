--- src/bluefish.c.orig	Sat Mar  8 04:55:40 2003
+++ src/bluefish.c	Thu Apr 17 23:04:31 2003
@@ -21,6 +21,7 @@
 #include <gtk/gtk.h>
 #include <unistd.h> /* getopt() */
 #include <stdlib.h> /* getopt() exit() and abort() on Solaris */
+#include <sys/stat.h>
 
 #include "bluefish.h"
 

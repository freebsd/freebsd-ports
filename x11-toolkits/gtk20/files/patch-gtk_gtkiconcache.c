--- gtk/gtkiconcache.c.orig	Sun Dec 12 16:09:13 2004
+++ gtk/gtkiconcache.c	Thu Dec 16 17:09:23 2004
@@ -21,6 +21,8 @@
 #include "gtkdebug.h"
 #include "gtkiconcache.h"
 #include <glib/gstdio.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #ifdef HAVE_MMAP
 #include <sys/mman.h>
@@ -29,8 +31,6 @@
 #include <windows.h>
 #include <io.h>
 #endif
-#include <sys/types.h>
-#include <sys/stat.h>
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif

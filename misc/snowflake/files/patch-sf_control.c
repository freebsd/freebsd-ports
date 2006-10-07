--- sf_control.c.orig	Mon Dec 21 00:18:55 1998
+++ sf_control.c	Sat Oct  7 16:20:33 2006
@@ -15,9 +15,8 @@
 #include <sys/shm.h>
 #include <sys/sem.h>
 
-#include "sf.h"
-
 #include "getopt.h"
+#include "sf.h"
 
 /* for iconify_window(): */
 #include <X11/Xlib.h>
@@ -266,7 +265,7 @@
 static char        xpm_filespec[MAX_FILESPEC+1]    = { 0 };
 
 static char        design_filespec[MAX_FILESPEC+1] = { 0 };
-static char        design_line = -1;
+static signed char        design_line = -1;
 static FILE*       design_file = (FILE*)0;
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

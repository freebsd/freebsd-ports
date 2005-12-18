--- Dclock.c.orig	Sat Dec 17 23:46:28 2005
+++ Dclock.c	Sat Dec 17 23:47:28 2005
@@ -9,9 +9,9 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
-#include <values.h>
+#include <limits.h>
 #include <time.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <errno.h>
 #include <X11/IntrinsicP.h>
 #include <X11/Xos.h>
@@ -171,7 +171,7 @@
     { XtNbellFile, "bellFile", XtRString, sizeof(String),
 	XtOffset(DclockWidget,dclock.bellfile), XtRString, (String)NULL},
     { XtNaudioPlay, "audioPlay", XtRString, sizeof(String),
-	XtOffset(DclockWidget,dclock.audioplay), XtRString, "/usr/bin/play"},
+	XtOffset(DclockWidget,dclock.audioplay), XtRString, "%%LOCALBASE%%/bin/play"},
 };
 
 /* Define the Dclock widget */

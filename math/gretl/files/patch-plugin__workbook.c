--- plugin/workbook.c.orig	Fri May 31 22:22:42 2002
+++ plugin/workbook.c	Sat Jul 27 08:45:00 2002
@@ -24,6 +24,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <glib.h>
+#include <wchar.h>
 
 #ifdef G_OS_WIN32
 # include "../winconfig.h"

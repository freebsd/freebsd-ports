--- gtksourceview/gtksourceregex.c.orig	Thu May 22 12:41:03 2003
+++ gtksourceview/gtksourceregex.c	Thu May 22 12:41:31 2003
@@ -28,7 +28,7 @@
 
 #ifdef NATIVE_GNU_REGEX
 #include <sys/types.h>
-#include <regex.h>
+#include <gnuregex.h>
 #else
 #include "gnu-regex/regex.h"
 #endif

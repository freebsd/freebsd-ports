--- src/Defaults.hs.orig	Thu Nov 27 16:42:13 2003
+++ src/Defaults.hs	Thu Nov 27 16:42:47 2003
@@ -6,9 +6,9 @@
 where
 
 afmPathDefault      = [
-#include <afmpath.h>
+#include "afmpath.h"
                       , "/usr/local/tex/lib/TeXPS/afm"]
 ebnfInputDefault    = ["."]
 rgbPathDefault	    = [
-#include <rgbpath.h>
+#include "rgbpath.h"
                       , "/usr/X11R6/lib/X11"]

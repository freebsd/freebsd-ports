--- utils/idna.c.orig	2019-09-15 12:06:06.236299000 +0200
+++ utils/idna.c	2019-09-15 12:06:07.393935000 +0200
@@ -27,7 +27,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
-#include <libutf8proc/utf8proc.h>
+#include <utf8proc.h>
 
 #include "netsurf/inttypes.h"
 

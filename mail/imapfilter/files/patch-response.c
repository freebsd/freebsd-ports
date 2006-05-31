--- response.c.orig	Wed May 31 20:36:08 2006
+++ response.c	Wed May 31 20:36:25 2006
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <strings.h>
 #include <ctype.h>
+#include <sys/types.h>
 #include <regex.h>
 
 #include "imapfilter.h"

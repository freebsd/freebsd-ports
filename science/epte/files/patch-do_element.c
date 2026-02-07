--- do_element.c.orig	2010-09-01 11:04:14.025987855 +0200
+++ do_element.c	2010-09-01 11:04:35.003159255 +0200
@@ -290,6 +290,7 @@ modification follow.
 
 */
 #include <errno.h>
+#include <string.h>
 #include "periodic.h"
 #include "info.h"
 

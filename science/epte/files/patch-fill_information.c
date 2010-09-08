--- fill_information.c.orig	2010-09-01 10:57:26.318201810 +0200
+++ fill_information.c	2010-09-01 10:58:12.521662864 +0200
@@ -290,6 +290,8 @@ modification follow.
 
 */
 
+#include <string.h>
+
 #include "periodic.h"
 #include "info.h"
 #include "text.h"

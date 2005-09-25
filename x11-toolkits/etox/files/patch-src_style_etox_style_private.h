--- src/style/etox_style_private.h.orig	Sun Sep 25 11:07:21 2005
+++ src/style/etox_style_private.h	Sun Sep 25 11:02:44 2005
@@ -2,7 +2,13 @@
 #define _ETOX_STYLE_PRIVATE_H
 
 #include <Ecore.h>
+#include <Ecore_Data.h>
 #include "Etox_Style.h"
+
+#include <stdlib.h>
+#include <stdio.h>
+#include <string.h>
+#include <limits.h>
 
 /*
  * The etox_style holds all information necessary for display and layout of the text

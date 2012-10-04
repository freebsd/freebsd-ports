--- gtksourceview/gtksourcelanguage.c.orig	2012-10-04 13:22:21.000000000 +0000
+++ gtksourceview/gtksourcelanguage.c	2012-10-04 13:22:33.000000000 +0000
@@ -30,8 +30,7 @@
 
 #include <libxml/xmlreader.h>
 
-#include <glib/gstdio.h>
-#include <glib/gmappedfile.h>
+#include <glib.h>
 
 #include "gtksourceview-i18n.h"
 

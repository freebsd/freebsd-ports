--- src/session.c.orig	2011-06-23 17:48:23.000000000 +0200
+++ src/session.c	2011-06-23 17:49:21.000000000 +0200
@@ -27,6 +27,7 @@
 #include "session.h"
 #include "application.h"
 #include <workbook.h>
+#include <workbook-priv.h>
 #include <workbook-view.h>
 #include <wbc-gtk.h>
 #include <gui-file.h>

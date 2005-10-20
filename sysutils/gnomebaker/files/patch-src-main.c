--- src/main.c.orig	Fri Oct  7 19:53:32 2005
+++ src/main.c	Fri Oct  7 19:54:29 2005
@@ -23,12 +23,12 @@
 #  include <config.h>
 #endif
 
+#include <libintl.h>
 #include "gnomebaker.h"
 #include <gnome.h>
 #include <glade/glade.h>
 #include "splashdlg.h"
 #include "gbcommon.h"
-#include <libintl.h>
 #include <locale.h>
 #include <gst/gst.h>
 

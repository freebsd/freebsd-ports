--- src/main.c.orig     Sat Feb 26 12:32:53 2005
+++ src/main.c  Sat Feb 26 12:33:03 2005
@@ -18,12 +18,12 @@
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

 const gchar* glade_file;

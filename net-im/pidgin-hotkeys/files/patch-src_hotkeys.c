--- ../gaim-hotkeys-0.2.2.orig/src/hotkeys.c	Mon May  7 09:02:50 2007
+++ src/hotkeys.c	Mon May  7 09:20:48 2007
@@ -22,15 +22,21 @@
 #include <gdk/gdkkeysyms.h>
 
 #define GAIM_PLUGINS
-#include <gaim.h>
-#include <gaim/version.h>
-#include <gaim/debug.h>
-#include <gaim/gtkblist.h>
-#include <gaim/gtkplugin.h>
-#include <gaim/gtkutils.h>
-#include <gaim/gtkdialogs.h>
-#include <gaim/gtkprefs.h>
-#include <gaim/gtkaccount.h>
+#include <pidgin.h>
+
+#include <libpurple/gaim-compat.h>
+#include <libpurple/conversation.h>
+#include <libpurple/debug.h>
+#include <libpurple/version.h>
+
+#include <pidgin/gtkgaim-compat.h>
+#include <pidgin/gtkconv.h>
+#include <pidgin/gtkblist.h>
+#include <pidgin/gtkplugin.h>
+#include <pidgin/gtkutils.h>
+#include <pidgin/gtkdialogs.h>
+#include <pidgin/gtkprefs.h>
+#include <pidgin/gtkaccount.h>
 
 #ifdef GDK_WINDOWING_X11
 #include <X11/keysym.h>
diff -ruN ../gaim-hotkeys-0.2.2.orig/src/hotkeys.c ./src/hotkeys.c

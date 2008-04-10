--- nx-X11/programs/Xserver/xkb/ddxLoad.c.orig	Thu May 18 14:14:35 2006
+++ nx-X11/programs/Xserver/xkb/ddxLoad.c
@@ -74,6 +74,9 @@
 
 #ifdef NXAGENT_SERVER
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #define NX_XKB_BASE_DIRECTORY            "/usr/lib/X11/xkb"
 #define NX_XKB_ALTERNATE_BASE_DIRECTORY  "/usr/share/X11/xkb"
 #define NX_KEYMAP_DIR_FILE               "keymap.dir"

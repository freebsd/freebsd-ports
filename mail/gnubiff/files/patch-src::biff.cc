--- src/biff.cc.bak	Sun Jan  9 14:29:14 2005
+++ src/biff.cc	Sun Jan  9 14:29:28 2005
@@ -35,6 +35,7 @@
 #include <fstream>
 #include <sstream>
 #include <map>
+#include <unistd.h>
 
 #ifdef USE_GNOME
 #  include "ui-applet-gnome.h"

--- yapet/cfgfile.h.orig	2013-09-05 20:47:04.000000000 +0200
+++ yapet/cfgfile.h	2013-09-05 20:47:46.000000000 +0200
@@ -35,6 +35,10 @@
 # include <string>
 #endif
 
+#ifdef HAVE_SSTREAM
+# include <sstream>
+#endif
+
 // Used for the YAPET::PWGEN::RNGENGINE type
 #include "pwgen/rng.h"
 

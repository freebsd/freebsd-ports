--- src/hooks/abstracthook.cc.orig	Sun Oct 19 06:57:26 2003
+++ src/hooks/abstracthook.cc	Mon Nov  3 19:54:31 2003
@@ -31,6 +31,7 @@
 #include "jabberhook.h"
 #include "rsshook.h"
 #include "ljhook.h"
+#include "msnhook.h"
 
 #include "md5.h"
 
@@ -325,6 +326,9 @@
 #endif
 #ifdef BUILD_LJ
 	case livejournal: return lhook;
+#endif
+#ifdef BUILD_MSN
+	case msn: return mhook;
 #endif
     }
 

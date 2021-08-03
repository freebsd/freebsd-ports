--- pan/general/file-util.cc.orig	2021-08-03 01:55:38 UTC
+++ pan/general/file-util.cc
@@ -22,17 +22,14 @@
 #include <cerrno>
 #include <cctype>
 
-extern "C"
-{
-  #include <unistd.h>
-  #include <sys/stat.h>
-  #include <sys/types.h>
-  #include <glib.h>
-  #include <glib/gi18n.h>
-  #ifndef G_OS_WIN32
-    #include <pwd.h>
-  #endif
-}
+#include <unistd.h>
+#include <sys/stat.h>
+#include <sys/types.h>
+#include <glib.h>
+#include <glib/gi18n.h>
+#ifndef G_OS_WIN32
+  #include <pwd.h>
+#endif
 
 #include "debug.h"
 #include "log.h"

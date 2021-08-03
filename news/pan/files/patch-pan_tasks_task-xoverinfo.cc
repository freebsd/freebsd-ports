--- pan/tasks/task-xoverinfo.cc.orig	2021-08-03 02:05:57 UTC
+++ pan/tasks/task-xoverinfo.cc
@@ -20,14 +20,12 @@
 #include <config.h>
 #include <cassert>
 #include <cerrno>
-extern "C" {
-  #define PROTOTYPES
-  #include <stdio.h>
-  #include <uulib/uudeview.h>
-  #include <glib/gi18n.h>
-  #include <gmime/gmime-utils.h>
-  #include <zlib.h>
-}
+#define PROTOTYPES
+#include <stdio.h>
+#include <uulib/uudeview.h>
+#include <glib/gi18n.h>
+#include <gmime/gmime-utils.h>
+#include <zlib.h>
 #include <fstream>
 #include <iostream>
 #include <pan/general/debug.h>

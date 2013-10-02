--- ./lib/src/libcommon.cpp.orig	2012-01-13 06:21:34.000000000 +0000
+++ ./lib/src/libcommon.cpp	2013-10-02 15:54:43.701934693 +0000
@@ -27,6 +27,7 @@
 #include <sstream>
 #include <glib.h>
 #include <glib/gstdio.h>
+#include <unistd.h>
 #include "libcommon.h"
 #ifdef _WIN32
 #  include <Shlwapi.h>

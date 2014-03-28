--- ./dict/src/dictmanagedlg.cpp.orig	2012-12-24 10:04:24.000000000 +0000
+++ ./dict/src/dictmanagedlg.cpp	2014-03-25 09:07:04.575980043 +0000
@@ -25,6 +25,7 @@
 #include <sys/stat.h>
 #include <glib/gi18n.h>
 #include <algorithm>
+#include <cstdlib>
 
 #ifdef _WIN32
 #  include <gdk/gdkwin32.h>

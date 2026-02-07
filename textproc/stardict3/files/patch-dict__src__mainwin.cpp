--- ./dict/src/mainwin.cpp.orig	2012-12-24 10:50:21.000000000 +0000
+++ ./dict/src/mainwin.cpp	2014-03-25 09:05:47.241985479 +0000
@@ -23,6 +23,7 @@
 #include <glib/gi18n.h>
 #include <gdk/gdkkeysyms.h>
 #include <algorithm>
+#include <cstdlib>
 
 #ifdef _WIN32
 #define VERSION "3.0.4"

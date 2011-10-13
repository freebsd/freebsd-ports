--- scribus/cupsoptions.cpp.orig	2011-10-13 19:10:47.000000000 +0200
+++ scribus/cupsoptions.cpp	2011-10-13 19:03:24.000000000 +0200
@@ -42,6 +42,7 @@
 #include "scconfig.h"
 #ifdef HAVE_CUPS
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #endif
 #include "util_icon.h"
 

--- scribus/cupsoptions.cpp.orig	2011-10-14 20:39:22.000000000 +0200
+++ scribus/cupsoptions.cpp	2011-10-14 20:39:39.000000000 +0200
@@ -33,6 +33,7 @@
 #include <qstringlist.h>
 #ifdef HAVE_CUPS
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #endif
 #include <qtooltip.h>
 extern QPixmap loadIcon(QString nam);

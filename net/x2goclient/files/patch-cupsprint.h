--- cupsprint.h.orig	2009-11-12 06:47:37.000000000 +0900
+++ cupsprint.h	2011-11-23 03:23:33.000000000 +0900
@@ -15,6 +15,7 @@
 #ifndef Q_OS_WIN
 #include <QStringList>
 #include <cups/cups.h>
+#include <cups/ppd.h>
 /**
 	@author Oleksandr Shneyder <oleksandr.shneyder@obviously-nice.de>
 */

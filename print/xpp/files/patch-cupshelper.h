--- cupshelper.h.orig	2002-05-28 08:49:45.000000000 -0700
+++ cupshelper.h	2011-11-29 13:10:22.991997261 -0800
@@ -34,6 +34,7 @@
 #define CUPSHELPER_H
 
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <cups/ipp.h>
 
 const char* cupsGetPassword(const char *prompt);

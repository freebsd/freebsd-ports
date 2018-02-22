--- libkcups/KCupsRequest.cpp.orig	2014-10-16 19:09:36 UTC
+++ libkcups/KCupsRequest.cpp
@@ -29,6 +29,7 @@
 #include <QStringBuilder>
 
 #include <cups/adminutil.h>
+#include <cups/ppd.h>
 
 #define CUPS_DATADIR    "/usr/share/cups"
 

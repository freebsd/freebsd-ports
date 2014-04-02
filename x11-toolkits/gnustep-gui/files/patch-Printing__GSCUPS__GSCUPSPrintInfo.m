--- ./Printing/GSCUPS/GSCUPSPrintInfo.m.orig	2011-02-07 18:08:33.000000000 +0000
+++ ./Printing/GSCUPS/GSCUPSPrintInfo.m	2014-03-31 15:14:03.000000000 +0000
@@ -32,7 +32,9 @@
 #import "AppKit/NSPrinter.h"
 #import "GSCUPSPrintInfo.h"
 #import "GSCUPSPrinter.h"
+#undef __BLOCKS__
 #include <cups/cups.h>
+#define __BLOCKS__
 
 
 @implementation GSCUPSPrintInfo

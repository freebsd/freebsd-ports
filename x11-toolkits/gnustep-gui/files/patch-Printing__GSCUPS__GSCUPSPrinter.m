--- ./Printing/GSCUPS/GSCUPSPrinter.m.orig	2011-03-14 21:45:39.000000000 +0000
+++ ./Printing/GSCUPS/GSCUPSPrinter.m	2014-03-31 15:14:03.000000000 +0000
@@ -48,7 +48,9 @@
 #import "GNUstepGUI/GSPrinting.h"
 #import "GSCUPSPrinter.h"
 
+#undef __BLOCKS__
 #include <cups/cups.h>
+#define __BLOCKS__
 
 
 NSString *GSCUPSDummyPrinterName = @"GSCUPSDummyPrinter";

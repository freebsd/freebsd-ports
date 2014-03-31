--- ./Printing/GSCUPS/GSCUPSPrintOperation.m.orig	2011-03-13 23:38:47.000000000 +0000
+++ ./Printing/GSCUPS/GSCUPSPrintOperation.m	2014-03-31 15:14:03.000000000 +0000
@@ -41,7 +41,9 @@
 #import <AppKit/NSPrintOperation.h>
 #import "GSGuiPrivate.h"
 #import "GSCUPSPrintOperation.h"
+#undef __BLOCKS__
 #include <cups/cups.h>
+#define __BLOCKS__
 
 
 //A subclass of GSPrintOperation, NOT NSPrintOperation.

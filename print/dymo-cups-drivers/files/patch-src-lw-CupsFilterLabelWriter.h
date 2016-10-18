--- src/lw/CupsFilterLabelWriter.h.orig	2012-02-07 13:22:37 UTC
+++ src/lw/CupsFilterLabelWriter.h
@@ -22,6 +22,7 @@
 #define hd8574b83_b264_47b2_8d33_a46ae75691d2
 
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <cups/raster.h>
 #include "LabelWriterDriver.h"
 #include "LabelWriterLanguageMonitor.h"

--- src/lm/CupsFilterLabelManager.h.orig	2012-02-07 13:22:38 UTC
+++ src/lm/CupsFilterLabelManager.h
@@ -22,6 +22,7 @@
 #define he780684b_6efc_428d_bfdb_c5422b1ed982
 
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <cups/raster.h>
 #include "LabelManagerDriver.h"
 #include "LabelManagerLanguageMonitor.h"
@@ -50,4 +51,4 @@ public:
 
 /*
  * End of "$Id: CupsFilterLabelManager.h 14880 2011-03-31 16:29:05Z aleksandr $".
- */
\ No newline at end of file
+ */

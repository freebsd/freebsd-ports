--- src/common/CupsPrintEnvironment.h.orig	2020-06-27 09:49:12 UTC
+++ src/common/CupsPrintEnvironment.h
@@ -21,6 +21,8 @@
 #ifndef h952b1c81_8931_433a_8479_7ae6d8e85a86
 #define h952b1c81_8931_433a_8479_7ae6d8e85a86
 
+#include <cups/backend.h>
+#include <cups/sidechannel.h>
 #include "PrinterDriver.h"
 
 namespace DymoPrinterDriver

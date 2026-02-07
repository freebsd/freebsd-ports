Fix Clang6 warning, mismatched guard defines

--- include/UserReport.h.orig	2018-07-04 10:30:57 UTC
+++ include/UserReport.h
@@ -26,7 +26,7 @@
 */
 
 #ifndef USERREPORT_H
-#define USREREPORT_H
+#define USERREPORT_H
 
 #include "srg.h"
 #include "Report.h"

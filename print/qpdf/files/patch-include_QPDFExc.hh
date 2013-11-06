--- include/qpdf/QPDFExc.hh.orig	2013-10-22 10:56:42.542484811 +0400
+++ include/qpdf/QPDFExc.hh	2013-10-22 10:57:02.738482806 +0400
@@ -13,6 +13,7 @@
 
 #include <qpdf/Constants.h>
 #include <stdexcept>
+#include <string>
 
 class QPDFExc: public std::runtime_error
 {

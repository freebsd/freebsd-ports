--- src/parser/HtmlTokenizer.cc.orig	2013-11-03 22:09:11.000000000 +0100
+++ src/parser/HtmlTokenizer.cc	2013-11-03 22:10:10.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "AbstractTokenReceiver.h"
 #include "StringReader.h"
 #include "RegularExpression.h"

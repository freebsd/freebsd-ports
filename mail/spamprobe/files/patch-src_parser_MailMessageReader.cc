--- src/parser/MailMessageReader.cc.orig	2013-11-03 22:12:15.000000000 +0100
+++ src/parser/MailMessageReader.cc	2013-11-03 22:12:34.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "RegularExpression.h"
 #include "MailMessage.h"
 #include "MailMessageList.h"

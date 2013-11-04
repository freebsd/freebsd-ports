--- src/parser/MbxMailMessageReader.cc.orig	2013-11-03 22:13:39.000000000 +0100
+++ src/parser/MbxMailMessageReader.cc	2013-11-03 22:14:42.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include <stdexcept>
 #include "MailMessage.h"
 #include "MailMessageList.h"

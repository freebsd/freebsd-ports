--- src/cmdlineextractor.h.orig	2010-05-30 21:11:10.000000000 +0200
+++ src/cmdlineextractor.h	2014-01-25 18:46:51.620972183 +0100
@@ -20,7 +20,7 @@
 #include "oggComment.h"
 #include "blendElement.h"
 
-const std::string validChars ( "0123456789,x" );
+const std::string validChars ( "0123456789,x:" );
 const std::string
 validTextChars ( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 /\\.,=;:-_" );
 

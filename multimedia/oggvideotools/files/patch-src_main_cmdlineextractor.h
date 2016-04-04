--- src/main/cmdlineextractor.h.orig	2015-10-05 06:33:52 UTC
+++ src/main/cmdlineextractor.h
@@ -21,7 +21,7 @@
 #include "blendElement.h"
 #include "effectorTypes.h"
 
-const std::string validChars ( "0123456789,x" );
+const std::string validChars ( "0123456789,x:" );
 const std::string
 validTextChars ( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 /\\.,=;:-_" );
 

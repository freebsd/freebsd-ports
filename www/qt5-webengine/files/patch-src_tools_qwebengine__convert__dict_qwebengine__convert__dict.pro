--- src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro.orig	2023-11-09 12:28:27 UTC
+++ src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro
@@ -43,7 +43,7 @@ QMAKE_TARGET_DESCRIPTION = "Qt WebEngine Dictionary Co
 
 QMAKE_TARGET_DESCRIPTION = "Qt WebEngine Dictionary Converter"
 
-CONFIG += c++14
+CONFIG += c++1z
 
 # Support converting dictionaries in a prefix build, by supplying
 # the path to the ICU data file located in the Qt build path, rather

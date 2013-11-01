--- src/ppdfile.cpp.orig	2009-02-06 11:49:10.000000000 +0000
+++ src/ppdfile.cpp
@@ -282,7 +282,7 @@ bool PPDFile::Value::operator != (const
  * Opérateur d'assignation
  * Assignment operator
  */
-void PPDFile::Value::operator = (const PPDFile::Value::Value &val)
+void PPDFile::Value::operator = (const PPDFile::Value &val)
 {
     if (_preformatted)
         delete[] _preformatted;

--- src/core/CLucene/analysis/AnalysisHeader.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/analysis/AnalysisHeader.cpp	2014-06-24 18:57:17.000000000 -0400
@@ -212,7 +212,7 @@
     sb.append(_T(","));
     sb.appendInt( _endOffset );
 
-    if (!_tcscmp( _type, _T("word")) == 0 ){
+    if (_tcscmp( _type, _T("word")) != 0) {
       sb.append(_T(",type="));
       sb.append(_type);
     }

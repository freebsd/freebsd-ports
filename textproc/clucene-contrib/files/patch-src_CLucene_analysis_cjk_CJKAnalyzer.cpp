--- src/CLucene/analysis/cjk/CJKAnalyzer.cpp.orig	2007-02-10 13:56:33.000000000 +0000
+++ src/CLucene/analysis/cjk/CJKAnalyzer.cpp	2010-06-22 07:00:25.000000000 +0000
@@ -1,4 +1,5 @@
 #include "CLucene/StdHeader.h"
+#include "CLucene/analysis/Analyzers.h"
 #include "CJKAnalyzer.h"
 
 CL_NS_DEF2(analysis,cjk)
@@ -180,4 +181,34 @@
 	return true;
 }
 
+CJKAnalyzer::CJKAnalyzer() {
+    StopFilter::fillStopTable( &stopTable, CJKAnalyzer::STOP_WORDS);
+}
+
+CJKAnalyzer::CJKAnalyzer(const TCHAR** stopWords) {
+    StopFilter::fillStopTable(&stopTable, stopWords);
+}
+
+CJKAnalyzer::~CJKAnalyzer() {
+}
+
+const TCHAR* CJKAnalyzer::STOP_WORDS[]  = {
+    _T("a"), _T("and"), _T("are"), _T("as"), _T("at"), _T("be"),
+    _T("but"), _T("by"), _T("for"), _T("if"), _T("in"),
+    _T("into"), _T("is"), _T("it"), _T("no"), _T("not"),
+    _T("of"), _T("on"), _T("or"), _T("s"), _T("such"), _T("t"),
+    _T("that"), _T("the"), _T("their"), _T("then"),
+    _T("there"), _T("these"), _T("they"), _T("this"),
+    _T("to"), _T("was"), _T("will"), _T("with"),
+    _T("www"),
+    NULL
+};
+
+
+TokenStream* CJKAnalyzer::tokenStream(const TCHAR* fieldName, Reader* reader) {
+    TokenStream* ret = _CLNEW CJKTokenizer(reader);
+    ret = _CLNEW StopFilter(ret,true, &stopTable);
+    return ret;
+}
+
 CL_NS_END2

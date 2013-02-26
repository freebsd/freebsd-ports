Index: Source/WebCore/css/CSSParser.cpp
===================================================================
--- Source/WebCore/css/CSSParser.cpp	(revision 124098)
+++ Source/WebCore/css/CSSParser.cpp	(revision 124099)
@@ -115,5 +115,5 @@
 #endif

-extern int cssyyparse(void* parser);
+extern int cssyyparse(WebCore::CSSParser*);

 using namespace std;


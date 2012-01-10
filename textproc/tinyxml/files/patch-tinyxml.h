--- tinyxml.h.orig	2012-01-07 23:11:37.561366901 +0100
+++ tinyxml.h	2012-01-07 23:11:58.085366340 +0100
@@ -26,6 +26,8 @@
 #ifndef TINYXML_INCLUDED
 #define TINYXML_INCLUDED
 
+#define TIXML_USE_STL
+
 #ifdef _MSC_VER
 #pragma warning( push )
 #pragma warning( disable : 4530 )

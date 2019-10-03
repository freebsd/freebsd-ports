Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

In file included from Source/WebCore/dom/DOMAllInOne.cpp:67:
Source/WebCore/dom/Document.cpp:4410:39: error: expected ';' after do/while statement
    U16_NEXT(characters, i, length, c)
                                      ^
                                      ;
Source/WebCore/dom/Document.cpp:4415:43: error: expected ';' after do/while statement
        U16_NEXT(characters, i, length, c)
                                          ^
                                          ;
Source/WebCore/dom/Document.cpp:4477:46: error: expected ';' after do/while statement
        U16_NEXT(qualifiedName, i, length, c)
                                             ^
                                             ;

--- Source/WebCore/dom/Document.cpp.orig	2019-06-26 16:25:02 UTC
+++ Source/WebCore/dom/Document.cpp
@@ -4407,12 +4407,12 @@ static bool isValidNameNonASCII(const UChar* character
     unsigned i = 0;
 
     UChar32 c;
-    U16_NEXT(characters, i, length, c)
+    U16_NEXT(characters, i, length, c);
     if (!isValidNameStart(c))
         return false;
 
     while (i < length) {
-        U16_NEXT(characters, i, length, c)
+        U16_NEXT(characters, i, length, c);
         if (!isValidNamePart(c))
             return false;
     }
@@ -4474,7 +4474,7 @@ bool Document::parseQualifiedName(const String& qualif
 
     for (unsigned i = 0; i < length;) {
         UChar32 c;
-        U16_NEXT(qualifiedName, i, length, c)
+        U16_NEXT(qualifiedName, i, length, c);
         if (c == ':') {
             if (sawColon) {
                 ec = NAMESPACE_ERR;

Regressed by https://github.com/unicode-org/icu/commit/480bec3ea652

In file included from DerivedSources/WebCore/unified-sources/UnifiedSource-be65d27a-6.cpp:4:
Source/WebCore/dom/Document.cpp:5075:39: error: expected ';' after do/while statement
    U16_NEXT(characters, i, length, c)
                                      ^
                                      ;
Source/WebCore/dom/Document.cpp:5080:43: error: expected ';' after do/while statement
        U16_NEXT(characters, i, length, c)
                                          ^
                                          ;
Source/WebCore/dom/Document.cpp:5140:46: error: expected ';' after do/while statement
        U16_NEXT(qualifiedName, i, length, c)
                                             ^
                                             ;

--- Source/WebCore/dom/Document.cpp.orig	2019-08-26 14:55:45 UTC
+++ Source/WebCore/dom/Document.cpp
@@ -5072,12 +5072,12 @@ static bool isValidNameNonASCII(const UChar* character
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
@@ -5137,7 +5137,7 @@ ExceptionOr<std::pair<AtomicString, AtomicString>> Doc
 
     for (unsigned i = 0; i < length; ) {
         UChar32 c;
-        U16_NEXT(qualifiedName, i, length, c)
+        U16_NEXT(qualifiedName, i, length, c);
         if (c == ':') {
             if (sawColon)
                 return Exception { InvalidCharacterError };

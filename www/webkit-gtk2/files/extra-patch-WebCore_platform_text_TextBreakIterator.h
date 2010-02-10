Pr 143718, fix build with icu 4.3

--- WebCore/platform/text/TextBreakIterator.h.orig	2009-09-22 18:29:21.000000000 +0300
+++ WebCore/platform/text/TextBreakIterator.h	2010-02-10 08:49:59.000000000 +0200
@@ -26,7 +26,7 @@
 
 namespace WebCore {
 
-    class TextBreakIterator;
+    typedef struct UBreakIterator TextBreakIterator;
 
     // Note: The returned iterator is good only until you get another iterator.
 



--- MessageFactory.cc.orig	Tue Mar 11 07:38:41 2003
+++ MessageFactory.cc	Tue Mar 11 07:51:38 2003
@@ -28,7 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
-#include <strstream>
+#include <sstream>
 #include "Tokenizer.h"
 #include "MessageFactory.h"
 #include "RegularExpression.h"
@@ -50,11 +50,11 @@
 MessageFactory::MessageFactory()
   : m_minWordLength(2),
     m_maxWordLength(90),
+    m_phraser(new PhraseBuilder(2)),
     m_replaceNonAsciiChars(true),
     m_nonAsciiChar('z'),
     m_removeHTML(true),
-    m_headersToInclude(NORMAL_HEADERS),
-    m_phraser(new PhraseBuilder(2))
+    m_headersToInclude(NORMAL_HEADERS)
 {
 }
 
@@ -299,7 +299,7 @@
     text += ' ';
   } else if (entity[0] == '#') {
     int code = 0;
-    istrstream in(entity.c_str() + 1);
+    istringstream in(entity.c_str() + 1);
     in >> code;
     text += (char)code;
   } else {

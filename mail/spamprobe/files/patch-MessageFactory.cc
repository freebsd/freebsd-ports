
$FreeBSD$

--- MessageFactory.cc.orig	Mon Jan 26 22:49:13 2004
+++ MessageFactory.cc	Thu Feb 12 16:25:43 2004
@@ -27,7 +27,7 @@
 //
 
 #include <set>
-#include <strstream>
+#include <sstream>
 #include "FrequencyDB.h"
 #include "Tokenizer.h"
 #include "MessageFactory.h"
@@ -58,13 +58,13 @@
 MessageFactory::MessageFactory()
   : m_minWordLength(1),
     m_maxWordLength(90),
+    m_phraser(new PhraseBuilder(2)),
     m_replaceNonAsciiChars(true),
     m_nonAsciiChar('z'),
     m_removeHTML(true),
     m_keepSuspiciousTags(false),
     m_ignoreBody(false),
-    m_headersToInclude(NORMAL_HEADERS),
-    m_phraser(new PhraseBuilder(2))
+    m_headersToInclude(NORMAL_HEADERS)
 {
 }
 
@@ -383,7 +383,7 @@
     text += ' ';
   } else if (entity[0] == '#') {
     int code = 0;
-    istrstream in(entity.c_str() + 1);
+    istringstream in(entity.c_str() + 1);
     in >> code;
     text += safe_char(code);
   } else {

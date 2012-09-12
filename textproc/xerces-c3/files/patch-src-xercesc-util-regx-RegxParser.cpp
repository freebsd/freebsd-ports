--- src/xercesc/util/regx/RegxParser.cpp.orig
+++ src/xercesc/util/regx/RegxParser.cpp
@@ -691,11 +691,11 @@ RangeToken* RegxParser::parseCharacterClass(const bool useNRange) {
                     || (ch == chDash && getCharData() == chCloseSquare && firstLoop))) {
                 // if regex = [-] then invalid...
                 // '[', ']', '-' not allowed and should be escaped
-                XMLCh chStr[] = { ch, chNull };
+                XMLCh chStr[] = { static_cast<XMLCh>(ch), chNull };
                 ThrowXMLwithMemMgr2(ParseException,XMLExcepts::Parser_CC6, chStr, chStr, getMemoryManager());
             }
             if (ch == chDash && getCharData() == chDash && getState() != REGX_T_BACKSOLIDUS && !wasDecoded) {
-                XMLCh chStr[] = { ch, chNull };
+                XMLCh chStr[] = { static_cast<XMLCh>(ch), chNull };
                 ThrowXMLwithMemMgr2(ParseException,XMLExcepts::Parser_CC6, chStr, chStr, getMemoryManager());
             }
 
@@ -720,7 +720,7 @@ RangeToken* RegxParser::parseCharacterClass(const bool useNRange) {
                 else {
 
                     XMLInt32 rangeEnd = getCharData();
-                    XMLCh rangeEndStr[] = { rangeEnd, chNull };
+                    XMLCh rangeEndStr[] = { static_cast<XMLCh>(rangeEnd), chNull };
 
                     if (type == REGX_T_CHAR) {
 
@@ -737,7 +737,7 @@ RangeToken* RegxParser::parseCharacterClass(const bool useNRange) {
                     processNext();
 
                     if (ch > rangeEnd) {
-                        XMLCh chStr[] = { ch, chNull };
+                        XMLCh chStr[] = { static_cast<XMLCh>(ch), chNull };
                         ThrowXMLwithMemMgr2(ParseException,XMLExcepts::Parser_Ope3, rangeEndStr, chStr, getMemoryManager());
                     }
 
@@ -845,7 +845,7 @@ XMLInt32 RegxParser::decodeEscaped() {
         break;
     default:
     {
-        XMLCh chString[] = {chBackSlash, ch, chNull};        
+        XMLCh chString[] = {chBackSlash, static_cast<XMLCh>(ch), chNull};        
         ThrowXMLwithMemMgr1(ParseException,XMLExcepts::Parser_Process2, chString, getMemoryManager());
     }
     }

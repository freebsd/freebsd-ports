--- src/xercesc/util/regx/ParserForXMLSchema.cpp.orig
+++ src/xercesc/util/regx/ParserForXMLSchema.cpp
@@ -156,7 +156,7 @@ XMLInt32 ParserForXMLSchema::decodeEscaped() {
         break;
     default:
         {
-        XMLCh chString[] = {chBackSlash, ch, chNull};        
+        XMLCh chString[] = {chBackSlash, static_cast<XMLCh>(ch), chNull};        
         ThrowXMLwithMemMgr1(ParseException,XMLExcepts::Parser_Process2, chString, getMemoryManager());
         }
     }

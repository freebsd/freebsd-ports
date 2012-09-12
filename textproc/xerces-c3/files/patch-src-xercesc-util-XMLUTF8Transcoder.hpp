--- src/xercesc/util/XMLUTF8Transcoder.hpp.orig
+++ src/xercesc/util/XMLUTF8Transcoder.hpp
@@ -107,7 +107,7 @@ void XMLUTF8Transcoder::checkTrailingBytes(const XMLByte      toCheck
     {
         char len[2]  = {(char)(trailingBytes+0x31), 0};
         char pos[2]  = {(char)(position+0x31), 0};
-        char byte[2] = {toCheck,0};
+        char byte[2] = {static_cast<char>(toCheck),0};
         ThrowXMLwithMemMgr3(UTFDataFormatException, XMLExcepts::UTF8_FormatError, pos, byte, len, getMemoryManager());
     }
 

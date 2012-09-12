--- src/xercesc/util/XMLUTF8Transcoder.cpp.orig
+++ src/xercesc/util/XMLUTF8Transcoder.cpp
@@ -178,7 +178,7 @@ XMLUTF8Transcoder::transcodeFrom(const  XMLByte* const          srcData
         if((gUTFByteIndicatorTest[trailingBytes] & *srcPtr) != gUTFByteIndicator[trailingBytes]) {
             char pos[2] = {(char)0x31, 0}; 
             char len[2] = {(char)(trailingBytes+0x31), 0};
-            char byte[2] = {*srcPtr,0};
+            char byte[2] = {static_cast<char>(*srcPtr),0};
             ThrowXMLwithMemMgr3(UTFDataFormatException, XMLExcepts::UTF8_FormatError, pos, byte, len, getMemoryManager());
         }
 
@@ -246,8 +246,8 @@ XMLUTF8Transcoder::transcodeFrom(const  XMLByte* const          srcData
                 //
                 if (( *srcPtr == 0xE0) && ( *(srcPtr+1) < 0xA0)) 
                 {
-                    char byte0[2] = {*srcPtr    ,0};
-                    char byte1[2] = {*(srcPtr+1),0};
+                    char byte0[2] = {static_cast<char>(*srcPtr)    ,0};
+                    char byte1[2] = {static_cast<char>(*(srcPtr+1)),0};
 
                     ThrowXMLwithMemMgr2(UTFDataFormatException
                                       , XMLExcepts::UTF8_Invalid_3BytesSeq
@@ -284,8 +284,8 @@ XMLUTF8Transcoder::transcodeFrom(const  XMLByte* const          srcData
 
                 if ((*srcPtr == 0xED) && (*(srcPtr+1) >= 0xA0))
                 {
-                    char byte0[2] = {*srcPtr,    0};
-                    char byte1[2] = {*(srcPtr+1),0};
+                    char byte0[2] = {static_cast<char>(*srcPtr),    0};
+                    char byte1[2] = {static_cast<char>(*(srcPtr+1)),0};
 
                      ThrowXMLwithMemMgr2(UTFDataFormatException
                               , XMLExcepts::UTF8_Irregular_3BytesSeq
@@ -310,8 +310,8 @@ XMLUTF8Transcoder::transcodeFrom(const  XMLByte* const          srcData
                 if (((*srcPtr == 0xF0) && (*(srcPtr+1) < 0x90)) ||
                     ((*srcPtr == 0xF4) && (*(srcPtr+1) > 0x8F))  )
                 {
-                    char byte0[2] = {*srcPtr    ,0};
-                    char byte1[2] = {*(srcPtr+1),0};
+                    char byte0[2] = {static_cast<char>(*srcPtr)    ,0};
+                    char byte1[2] = {static_cast<char>(*(srcPtr+1)),0};
 
                     ThrowXMLwithMemMgr2(UTFDataFormatException
                                       , XMLExcepts::UTF8_Invalid_4BytesSeq
@@ -344,7 +344,7 @@ XMLUTF8Transcoder::transcodeFrom(const  XMLByte* const          srcData
                  * surrogates, nor U+FFFE and U+FFFF (but it does allow other noncharacters).
                  ***/
                 char len[2]  = {(char)(trailingBytes+0x31), 0};
-                char byte[2] = {*srcPtr,0};
+                char byte[2] = {static_cast<char>(*srcPtr),0};
 
                 ThrowXMLwithMemMgr2(UTFDataFormatException
                                   , XMLExcepts::UTF8_Exceeds_BytesLimit
